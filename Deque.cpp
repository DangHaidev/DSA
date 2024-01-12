#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Deque
{
    public:
    Node* top;
    int size;
    Deque()
    {
        top = NULL;
        size = 0;
    }
    void push_front(int); // thêm ptu vào đầu
    void push_back(int); // thêm ptu vào cuối
    void pop_back(); // loai ptu ở cuối
    void pop_front(); // loai ptu ở đầu
    int front(); // tra ve gia tri o dqau
    int back(); // tra ve gtri ở cuối
    void print();
};

void Deque::push_front(int value)
{
    size++;
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}
void Deque::push_back(int value)
{
    Node* newNode = new Node(value);
    Node* temp = top;
    while (temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = newNode;
    size++;
}
void Deque::print()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}
void Deque::pop_front()
{
    Node* temp = top;
    top = temp->next;
    delete temp;
    size--;
}
void Deque::pop_back() // lỗi
{
    Node* temp = top;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
int Deque::front()
{
    return top->data;
}
int Deque::back()
{
    Node *temp = top;
    while(temp != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}
int main()
{
    Deque d;
    d.push_front(2);
    d.push_front(1);
    d.push_front(0);
    d.push_back(3);
    d.print();
}