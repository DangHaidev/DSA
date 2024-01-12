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

class Queue 
{
    public:
    Node* top;
    int size;
    Queue()
    {
        top = NULL;
        size = 0;
    }
    void push(int); // thêm phần tử vào cuối
    void pop(); // loại bỏ ptu ở đầu
    int front(); // trả về giá trị là phần tử đầu tiên 
    int sizeQ(); // trả về kích thước
    bool empty();
    void print();
};

void Queue::push(int value)
{
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}
void Queue::pop()
{
    Node* temp = top;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    delete temp;
    size--;
}
void Queue::print()
{
    Node *temp = top;
    int arr[size];
    int n = size;
    n -= 1;
    while(temp != NULL)
    {
        arr[n] = temp->data;
        temp = temp->next;
        n--;
    }
    for(int i = 0; i < size ; i ++)
    {
        cout << arr[i] << " ";
    }
}
int Queue::front()
{
    Node* temp = top;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}
int Queue::sizeQ()
{
    return size;
}
bool Queue::empty()
{
    return (top == NULL);
}
int main()
{
    Queue q;
}