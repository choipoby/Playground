#include <iostream>

template <typename T>
class SharedPtr
{
    T *ptr;
    int *counter;

public:
    explicit SharedPtr(T *ptr_)
    {
        ptr = ptr_;
        counter = new int(1);
    }

    ~SharedPtr()
    {
        ptr = nullptr;
        (*counter)--;
        if (*counter == 0)
        {
            delete ptr;
            delete counter;
        }
    }

    explicit SharedPtr(const SharedPtr<T> &rhs)
    {
        ptr = rhs.ptr;
        counter = rhs.counter;
        (*counter)++;
    }

    SharedPtr &operator=(const SharedPtr &rhs)
    {
        if (this != &rhs)
        {
            ptr = rhs.ptr;
            counter = rhs.counter;
            (*counter)++;
        }
        return *this;
    }

    T &operator*()
    {
        return *ptr;
    }

    T *operator->()
    {
        return ptr;
    }
};

int main()
{
    SharedPtr<int> a(new int(3));
    SharedPtr<int> b(a);

    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
}