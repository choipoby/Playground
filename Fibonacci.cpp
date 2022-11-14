#include <iostream>
#include <map>
std::map<int, int> cache;
int fib(int n)
{
#if 0
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;

    if (cache.find(n) != cache.end())
    {
        return cache[n];
    }

    int ret = fib(n - 1) + fib(n - 2);
    cache[n] = ret;
    return ret;
#else
    int a = 1;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return b;
#endif
}

int main()
{
    std::cout << fib(4) << std::endl;
}