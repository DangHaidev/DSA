#include <iostream>

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
    Node(int data) // tạo node
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    int size = 0;
    LinkedList()
    {
        head = NULL;
    }
    void insertNodeLast(int);        // thêm cuối
    void insertNodeF(int);           // thêm đầu
    void insert(int pos, int value); // thêm bất kỳ
    void printList();
    void deleteNode(int); // xóa bất kỳ
    void deleteFirst();   // xóa đầu
    void deleteLast();    // xóa cuối
};
void LinkedList::insert(int pos, int value)
{
    // thêm 1 số điều kiện ngoại lệ như là : list đang rỗng, pos = 1, hoặc pos không nằm trong size của list
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void LinkedList::insertNodeF(int value)
{
    // thêm trường hợp list còn rỗng
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
void LinkedList::insertNodeLast(int data)
{
    // tao một node mới
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void LinkedList::printList()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "\nDanh sach rong";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}

void LinkedList::deleteNode(int pos)
{
    if (head == nullptr)
    {
        cout << "\nMang rong";
        return;
    }
    if (pos < 1 || pos > size)
        return;
    Node *temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    Node *Npos = temp->next;
    temp->next = Npos->next;
    delete Npos;
}
void LinkedList::deleteFirst()
{
    // list rỗng
    Node *temp = head;
    head = temp->next;
    delete temp;
    size--;
}
void LinkedList::deleteLast()
{
    // list rỗng hoặc list chỉ có một địa chỉ
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = NULL;
    delete last;
}
int main()
{
    LinkedList list;
    while (1)
    {
        cout << "\n---------------------------------";
        cout << "\n1. Them vao dau";
        cout << "\n2. Them vao cuoi";
        cout << "\n3. Them vi tri bat ky";
        cout << "\n4. Xoa phan tu dau";
        cout << "\n5. Xoa phan tu cuoi";
        cout << "\n6. Xoa phan tu bat ky";
        cout << "\n7. In ra danh sach";
        cout << "\n---------------------------------";
        cout << "\n Nhap lua chon : ";
        int lc;
        cin >> lc;
        if (lc == 1)
        {
            int x;
            cout << "\nNhap gia tri muon them vao : ";
            cin >> x;
            list.insertNodeF(x);
        }
        else if (lc == 2)
        {
            int x;
            cout << "\nNhap gia tri muon them vao : ";
            cin >> x;
            list.insertNodeLast(x);
        } 
        else if ( lc == 3)
        {
            int x, pos;
            cout << "\nNhap vi tri va gia tri muon them vao : ";
            cin >>pos>> x;
            list.insert(pos,x);
        }
        else if ( lc == 4)
        {
            list.deleteFirst();
        }
        else if (lc == 5)
        {
            list.deleteLast();
        }
        else if (lc == 6)
        {
            int pos;
            cout<<"\nNhap vi tri muon xoa";
            cin>>pos;
            list.deleteNode(pos);
        }
        else if (lc == 7)
        {
            cout<<"\nDanh sach hien tai la : ";
            list.printList();
        }
        else
        {
            break;
        }
    }
    cout<<"\nDa thoat ctrinh!!!";
    return 0;
}