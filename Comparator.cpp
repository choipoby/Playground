#include <iostream>
#include <memory>
#include <set>
#include <functional> // std::greater
#include <algorithm>  // std::sort
using namespace std;

struct MyData
{
    string key;
    int value;
    MyData(const string &k, const int &v) : key(k), value(v) {}
};

struct Compare
{
    bool operator()(const shared_ptr<MyData> &lhs, const shared_ptr<MyData> &rhs)
    {
        return lhs->value < rhs->value;
    }
};

int main()
{
    set<shared_ptr<MyData>, Compare> myData;
    myData.insert(make_shared<MyData>("dog", 2));
    myData.insert(make_shared<MyData>("cat", 1));
    myData.insert(make_shared<MyData>("rat", 5));
    myData.insert(make_shared<MyData>("pig", 7));

    set<shared_ptr<MyData>, Compare>::iterator itr = myData.begin();
    while (itr != myData.end())
    {
        cout << "\t" << (*itr)->key << ": " << (*itr)->value << endl;
        itr++;
    }

    int numbers[] = {20, 40, 50, 10, 30};
    std::sort(numbers, numbers + 5, std::greater<int>());
    for (int i = 0; i < 5; i++)
        std::cout << numbers[i] << ' ';
    std::cout << '\n';
    return 0;
}