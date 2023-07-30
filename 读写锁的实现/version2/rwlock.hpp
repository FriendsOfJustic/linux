#include <pthread.h>

// 写者优先的锁
namespace sht
{
    class sht_rwlock
    {
    public:
        int sht_rwlock_init()
        {
            pthread_cond_init(&reader_cond, nullptr);
            pthread_cond_init(&writer_cond, nullptr);
            pthread_mutex_init(&m, nullptr);
        }

        int sht_rwlock_destroy()
        {
            pthread_cond_destroy(&reader_cond);
            pthread_cond_destroy(&writer_cond);
            pthread_mutex_destroy(&m);
        }

        int sht_rwlock_rdlock()
        {
            pthread_mutex_lock(&m);
            if (cur_state == 1)
            {
                // 当前在读模式，因为我们是写者优先所以我们看看是否有写者线程在等待
                // 如果有我们就先执行写者，让读者去排队
                // 如果没有，那么读锁就申请成功
                while (writer_num > 0)
                {
                    reader_num++;
                    pthread_cond_wait(&reader_cond, &m);
                    reader_num--;
                }
            }
            else if (cur_state == -1)
            {
                // 如果当前是写者模式，读者直接去排队
                reader_num++;
                pthread_cond_wait(&reader_cond, &m);
                reader_num--;
            }
            else
            {
                cur_state = 1;
            }

            pthread_mutex_unlock(&m);
        }

        int sht_rwlock_tryrdlock()
        {
            pthread_mutex_lock(&m);

            if (cur_state == 0 || cur_state == 1 && writer_num == 0)
            {
                pthread_mutex_unlock(&m);
                return 0;
            }
            return -1;
        }

        int sht_rwlock_wrlock()
        {
            pthread_mutex_lock(&m);
            if (cur_state == -1)
            {
                writer_num++;
                pthread_cond_wait(&writer_cond, &m);
                writer_num--;
            }
            else if (cur_state == 1)
            {
                writer_num++;
                pthread_cond_wait(&writer_cond, &m);
                writer_num--;
            }
            else
            {
                // 把状态改成写者模式
                cur_state = -1;
            }
            pthread_mutex_unlock(&m);
            return 1;
        }
        int sht_rwlock_trywrlock()
        {
            pthread_mutex_lock(&m);
            if (cur_state == -1)
            {
                pthread_mutex_unlock(&m);
                return 0;
            }
            return -1;
        }
        int sht_rwlock_unlock()
        {
            pthread_mutex_init(&m, nullptr);

            if (cur_state == 1)
            {

                if (writer_num > 0)
                {
                    cur_state = -1;
                    pthread_cond_signal(&writer_cond);
                }
                else
                {
                    if (reader_num > 0)
                    {
                        pthread_cond_signal(&reader_cond);
                    }
                    else
                        cur_state = 0; // 这一步一定不能丢，如果当前两个队列均为空时，要置为初始状态
                    // 不然线程就会卡住
                }
            }
            else if (cur_state == -1)
            {
                // 写者来还锁，如果写队列不为空 ，唤醒写队列中的写者（写者优先）
                // 如果写者队列空了，但是读者队列不为空，唤醒读者
                // 两个队列都为空，把状态置成初始状态

                if (writer_num > 0)
                {

                    pthread_cond_signal(&writer_cond);
                }
                else
                {
                    if (reader_num > 0)
                    {
                        cur_state = 1;
                        pthread_cond_signal(&reader_cond);
                    }
                    else
                        cur_state = 0;
                }
            }
            else
            {
                return -1;
            }

            pthread_mutex_unlock(&m);
        }

    private:
        pthread_cond_t reader_cond;
        pthread_cond_t writer_cond;
        pthread_mutex_t m;
        int reader_num; // 读者等待的数量
        int writer_num; // 写者等待的数量
        int cur_state;
        // 1 ： 代表读者模式
        // 0 : 代表锁是为获取的
        // -1 ：代表写者模式
    };
} // namespace sht
