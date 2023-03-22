#include <bits/stdc++.h>
#define ll long long
using namespace std;
// We use constant space;
// U can use stack and identify this also 

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

bool isPallindrom(Node* head){
    Node* slow = head;
    Node* fast = head;
    // while(!(fast==NULL || fast->next==NULL)){
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next==NULL)
        slow = slow->next;

    Node* s = reverse(slow);
    Node* f = head;
    while(s->next!=NULL){
        if(f->data!=s->data) return false;
        f = f->next;
        s = s->next;
    }
    return true;
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
    forth->data = 20;
    fifth->data = 10;
    sixth->data = 0;
    
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    Print(head);
    cout<<endl;

    

    if(isPallindrom(head))
       cout<<"List is pallindrom"<<endl;
    else   cout<<"List is not pallindrom"<<endl;
   
    return 0;
}