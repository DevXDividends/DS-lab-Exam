#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;
    Node(int val)
    {
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

void insert(Node *&head, int val)
{
    Node *nn = new Node(val);

    if (!head)
    {
        head = nn;
        return;
    }

    if (val < head->data)
    {
        nn->next = head;
        head->back = nn;
        head = nn;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data < val)
        temp = temp->next;

    nn->next = temp->next;
    nn->back = temp;

    if (temp->next != nullptr)
        temp->next->back = nn;

    temp->next = nn;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
void findEven(Node *&head)
{
    Node *temp = head;
    cout << "\nNodes with Even Data: ";
    while (temp != nullptr)
    {
        if ((temp->data) % 2 == 0)
        {
            cout << temp->data << "->";
        }
        temp = temp->next;

    }
    cout<<"\n";
}
void swapp(Node *&head)
{
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    swap(head->data, temp->data);
}
int main()
{

    Node *head = nullptr;
    int ch;

    do
    {
        cout << "\n1.Insert ";
        cout << "\n2.Find Even Nodes";
        cout << "\n3.Swap first and last node:";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int val;
            cout << "Enter value: ";
            cin >> val;
            insert(head, val);
            cout << "\n";
            display(head);
            break;
        case 2:
            findEven(head);

            break;
        case 3:
            swapp(head);
            cout<<"\n";
            cout<<"After swapping: ";
            display(head);
            break;
        default:
            cout << "Invalid choice";
        }

    } while (ch != 4);

    return 0;
}
