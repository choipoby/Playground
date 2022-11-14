#include <cstdint>
#include <cstring>
#include <new>

using namespace std;
class RingBuffer
{
public:
    RingBuffer(uint32_t size)
    {
        buffer = new (nothrow) uint8_t[size];
        capacity = size;
    }

    ~RingBuffer()
    {
        delete[] buffer;
    }

    int write(uint8_t *src, int size)
    {
        if (!size || src == nullptr)
            return 0;

        int writeSize = (capacity - used > size) ? size : capacity - used;
        if (tail > head)
        {
            memcpy(buffer + head, src, writeSize);
            head += writeSize;
        }
        else
        {
            int frontSize = (writeSize > (capacity - head)) ? capacity - head : writeSize;
            memcpy(buffer + head, src, frontSize);
            head += frontSize;
            head = head % capacity;
            int backSize = writeSize - frontSize;
            if (backSize)
            {
                memcpy(buffer, src + frontSize, backSize);
                head = backSize;
            }
        }
        used += writeSize;
        used = used % capacity;
        return writeSize;
    }

    int read(int8_t *dst, int size)
    {
        if (!size || dst == nullptr)
            return 0;

        int readSize = size > used ? used : size;
        if (head > tail)
        {
            memcpy(dst, buffer + tail, readSize);
            tail += readSize;
        }
        else
        {
            int frontSize = readSize > (capacity - tail) ? capacity - tail : readSize;
            memcpy(dst, buffer + tail, frontSize);
            tail += frontSize;
            int backSize = readSize - frontSize;
            if (backSize)
            {
                memcpy(dst + readSize, buffer, backSize);
                tail += backSize;
            }
        }
        tail = tail % capacity;
        used -= readSize;
        return readSize;
    }

private:
    uint8_t *buffer{nullptr};
    uint32_t capacity{0};
    uint32_t used{0};
    uint32_t head{0};
    uint32_t tail{0};
};

int main()
{
    RingBuffer ringBuffer(100);
    return 0;
}