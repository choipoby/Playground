#include <memory>
#include <atomic>
#include <iostream>
#include <thread>
template <typename T>
class LockFreeStack
{
private:
    struct Node
    {
        std::shared_ptr<T> data;
        Node *next;
        Node(T const &_data) : data(std::make_shared<T>(_data))
        {
        }
    };
    std::atomic<Node *> head;

public:
    void push(T const &data)
    {
        Node *newNode = new Node(data);
        newNode->next = head.load();
        while (!head.compare_exchange_weak(newNode->next, newNode))
            ;
    }
    std::shared_ptr<T> pop()
    {
        Node *oldHead = head.load();
        while (oldHead && !head.compare_exchange_weak(oldHead, oldHead->next))
            ;
        return oldHead ? oldHead->data : std::shared_ptr<T>();
    }
};

int main()
{
    LockFreeStack<int> stack;
    std::thread t1([&]()
                   { stack.push(1); });
    std::thread t2([&]()
                   { std::shared_ptr<int> a = stack.pop();
                   std::cout << *a << std::endl; });
}