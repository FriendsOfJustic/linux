
#include <thread>
namespace sht
{
    class ThreadGaurd
    {
    public:
        explicit ThreadGaurd(std::thread &x)
            : _t(x)
        {
        }

        ~ThreadGaurd()
        {
            if (_t.joinable()) // 查看是否可以join  虽然把拷贝构造给封了，但是我构造可以构造多个😅
                _t.join();
        }

        ThreadGaurd(const ThreadGaurd &x) = delete;
        ThreadGaurd &operator=(const ThreadGaurd &x) = delete;

    private:
        std::thread &_t;
    };
}