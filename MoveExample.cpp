#include <string>
#include <utility>
using namespace std;

class MoveMe
{
    char *data;

public:
    MoveMe(MoveMe &&other) : data(std::exchange(other.data, nullptr))
    {
    }

    MoveMe &operator=(MoveMe &&other)
    {
        if (this == &other)
            return *this;
    }

    ~MoveMe()
    {
        if (data)
            delete data;
    }
};

int main()
{
    int *a;
    a = new int;
    delete[] a;
}