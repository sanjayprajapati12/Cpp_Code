#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *next; // struct Node *next in c 
};

Node* reverse(Node* head){
    Node* next ;
    Node* current = head ;
    Node* prev = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current=next; 
    }
    return prev;
}

Node* reverseRecursive(Node *prev)
{
    if (prev->next == NULL){
       return prev;
    }
    Node* rest = reverseRecursive(prev->next);

    Node* q = prev->next;
    q->next = prev;
    prev->next = NULL;

    return rest;
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

    Print(head);
    cout<<endl;

    Node* head1 = reverse(head);
    cout<<"After reversing the list\n";
    Print(head1);
    cout<<endl;

    Node* head2 = reverseRecursive(head1);
    cout<<"After reversing the list recursively\n";
    Print(head2);
    cout<<endl;

    return 0;
}