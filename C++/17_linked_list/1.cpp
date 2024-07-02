/*
array: Single block of memory with partition. {2, 3, 1, 6}
linked list: Multiple block of memory linked to each other.({2}, {3}, {1}, {6})
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtEnd(Node *&head, int val)
{
    Node *new_node = new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertAtPosition(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }

    Node *new_node = new Node(val);
    Node *temp = head;
    int current_pos = 0;

    while (current_pos != pos - 1)
    {
        temp = temp->next;
        current_pos++;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void update(Node *head, int val, int pos)
{
    Node *temp = head;
    int current_pos = 0;

    while (current_pos != pos)
    {
        temp = temp->next;
        current_pos++;
    }
    temp->val = val;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Node *n = new Node(1);
    // cout << n->val << " " << n->next << endl;

    Node *head = NULL;
    insertAtHead(head, 2);
    display(head);

    insertAtHead(head, 3);
    display(head);

    insertAtEnd(head, 9);
    display(head);

    insertAtPosition(head, 7, 2);
    display(head);

    update(head, 13, 1);
    display(head);

    return 0;
}