#include <iostream>
using namespace std;
class doublelinkedlist
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;
    Node* tail;
public:
    doublelinkedlist() : head(nullptr), tail(nullptr) {}
    ~doublelinkedlist()
    {
        Node* current = head;
        while (current)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtPosition(int val, int pos)
    {
        if (pos <= 0)
        {
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* current = head;
        for (int i = 0; i < pos - 1 && current; ++i)
        {
            current = current->next;
        }
        if (!current)
        {
            insertAtEnd(val);
        }
        else
        {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next)
                current->next->prev = newNode;
            current->next = newNode;
            if (newNode->next == nullptr)
                tail = newNode;
        }
    }
    void deleteAtPosition(int pos)
    {
        if (!head)
            return;
        Node* current = head;
        for (int i = 0; i < pos && current; ++i)
        {
            current = current->next;
        }
        if (!current)
            return;
        if (current->prev)
            current->prev->next = current->next;
        else
            head = current->next;
        if (current->next)
            current->next->prev = current->prev;
        else
            tail = current->prev;
        delete current;
    }
    void displayForward()
    {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void displayBackward()
    {
        Node* current = tail;
        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main()
{
    doublelinkedlist dll;
    dll.insertAtEnd(10);
    dll.insertAtBeginning(5);
    dll.insertAtPosition(7, 1);
    dll.displayForward();   
    dll.displayBackward();  
    dll.deleteAtPosition(1);
    dll.displayForward();
    return 0;
}