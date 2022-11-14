#include <utility>
#include <iostream>

class DoubleFree
{
    int *data;

public:
    DoubleFree()
    {
        data = new int(0);
    }

    DoubleFree(int a)
    {
        data = new int(a);
    }
    ~DoubleFree()
    {
        if (data)
        {
            delete data;
            data = nullptr;
        }
    }

    DoubleFree(const DoubleFree &other)
    {
        data = new int(*(other.data));
    }

    DoubleFree(DoubleFree &&other) : data(std::exchange(other.data, nullptr))
    {
    }

    DoubleFree &operator=(const DoubleFree &other)
    {
        if (this != &other)
        {
            this->data = new int(*(other.data));
        }
        return *this;
    }

    DoubleFree &operator=(DoubleFree &&other)
    {
        if (this != &other)
        {
            delete[] this->data;
            this->data = std::exchange(other.data, nullptr);
        }
        return *this;
    }

    int getValue()
    {
        return *data;
    }
};

int main()
{
    DoubleFree a(1);
    DoubleFree b(a);
    DoubleFree c(std::move(b));
    DoubleFree d;
    d = std::move(c);
    std::cout << d.getValue() << std::endl;
}