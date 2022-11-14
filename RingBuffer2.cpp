template <class T>
class RingBuffer2
{
public:
    RingBuffer2(uint32_t size)
    {
    }

    ~RingBuffer2()
    {
    }

    bool push(T &item)
    {
        return false;
    }

    bool pop(T &item)
    {
        return false;
    }

private:
    vector<T> buffer;
};