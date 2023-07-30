#include <pthread.h>
// 使用两个mutex来实现读写锁
namespace sht
{
    class sht_rwlock
    {
    private:
        pthread_mutex_t m1; // 用来锁读者 目的是为了保护read_num这个临界资源
        pthread_mutex_t m2; // 用来锁写者 用来控制读者之间的互斥
        int read_num = 0;   // 记录读者的数量
        int cur_state = 0;
        // 0 ： 表示没有上锁
        // 1 ：当前在读模式
        // -1 ：当前在写模式

    public:
        // 初始化
        int sht_rwlock_init()
        {

            pthread_mutex_init(&m1, nullptr);
            pthread_mutex_init(&m2, nullptr);
            return 0;
        }

        int sht_rwlock_destroy()
        {
            pthread_mutex_destroy(&m1);
            pthread_mutex_destroy(&m2);
        }

        int sht_rwlock_rdlock()
        {
            pthread_mutex_lock(&m1);
            read_num++;

            if (read_num == 1)
                pthread_mutex_lock(&m2);
            // 改变成读者状态必须一定要放在申请到读者锁之后！！！！！！！！
            cur_state = 1;

            // 读者之间不是互斥关系，所以要解锁，否则其他读者进不来
            pthread_mutex_unlock(&m1);
            return 0;
        }

        int sht_rwlock_tryrdlock()
        {
            int ret1 = pthread_mutex_trylock(&m1);
            if (ret1 != 0)
                return -1;

            if (read_num == 1)
            {
                int ret2 = pthread_mutex_trylock(&m2);
                if (ret2 != 0)
                    return -1;
            }
            read_num++;
            cur_state = 1;

            pthread_mutex_unlock(&m1);
            return 0;
        }

        int sht_rwlock_wrlock()
        {
            int ret = pthread_mutex_lock(&m2);
            // 如果能走到这一步代表：读者申请到锁了，而读者和所有人互斥，所以我们改变状态并不归还锁
            cur_state = -1;
            return ret;
        }

        int sht_rwlock_trywrlock()
        {
            int ret = pthread_mutex_lock(&m2);
            if (ret != 0)
                return -1;
            // 如果能走到这一步代表：读者申请到锁了，而读者和所有人互斥，所以我们改变状态并不归还锁
            cur_state = -1;
            return ret;
        }

        int sht_rwlock_unlock()
        {
            if (cur_state == -1)
            {
                // 写者还锁
                pthread_mutex_unlock(&m2);
                cur_state = 0;
            }
            else if (cur_state == 1)
            {
                // 读者还锁
                pthread_mutex_lock(&m1);

                if (read_num == 1)
                    pthread_mutex_unlock(&m2);

                read_num--;

                pthread_mutex_unlock(&m1);
            }
            else
                return -1;

            return 0;
        }
    };

} // namespace sht
