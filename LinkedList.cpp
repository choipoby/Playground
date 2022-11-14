#include <iostream>

template <typename T>
class LinkedList
{
    struct Node
    {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr)
        {
        }
    };
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // push to tail
    void push(T d)
    {
        Node *node = new Node(d);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // pop from head
    bool pop(T &d)
    {
        if (head == nullptr)
        {
            return false;
        }
        Node *temp = head;
        d = head->data;
        head = head->next;
        delete temp;
        return true;
    }
};

int main()
{
    LinkedList<int> list;
    list.push(3);
    list.push(4);
    int out;
    list.pop(out);
    std::cout << out << std::endl;
    list.pop(out);
    std::cout << out << std::endl;
}