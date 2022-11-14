#include <iostream>
using namespace std;

void bar(string &&z)
{
    cout << "z: " << z << endl;
}

void foo(string &&x)
{
    // bar(x); // --> this will compile error since x is lvalue
    bar(std::move(x)); // this is fine since we cast lvalue x to rvalue
    // string y = x; // don't do this something like this after std::move(x)
    x = "world";
    cout << "x: " << x << endl;
}

int main()
{
    string hello = "hello";
    foo(std::move(hello));
    return 0;
}