#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *prev; // struct Node *next in c 
    Node *next; // struct Node *next in c 
};


void Print(Node* head)
{
    cout << "List is : ";
    if(head->next==NULL){
        while (head != NULL)
        {
        cout << head->data << " ";
        head = head->prev;
        }
    }
    else{
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
    cout << "\n";
}

int main()
{
    // struct Node *head = malloc(sizeof(struct Node)); in c
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *forth = new Node();
    Node *fifth = new Node();
    Node *sixth = new Node();

    head->data = 0;
    first->data = 10;
    second->data = 20;
    third->data = 30;
    forth->data = 40;
    fifth->data = 50;
    sixth->data = 60;
    
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    head->prev = NULL;
    first->prev = head;
    second->prev =first;
    third->prev = second;
    forth->prev = third;
    fifth->prev = forth;
    sixth->prev = fifth;

    Print(head);
    Print(sixth);
    return 0;
}