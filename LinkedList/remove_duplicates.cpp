#include <bits/stdc++.h>
#define ll long long
using namespace std;
// This is for sorted list
struct Node
{
    int data;
    Node *next;  // struct Node *next in c 
};

void remove(Node* head){
    Node* f = head;
    Node* s = head->next;
    while(s!=NULL){
        while(s->data==f->data){
            s = s->next;
            f->next = s; 
        }
        f=f->next;
        s=s->next;
    }
}

void Print(Node* head)
{
    cout << "List is : ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
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
    second->data = 10;
    third->data = 30;
    forth->data = 30;
    fifth->data = 30;
    sixth->data = 60;
    
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout<<"Main list\n";
    Print(head);

    cout<<"After removing duplicates\n";
    remove(head);
    Print(head);

    return 0;
}