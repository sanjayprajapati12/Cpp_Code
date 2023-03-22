#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *next; // struct Node *next in c 
};


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

Node* deleteFirst(Node *head){
    Node* p = head;
    head = head->next;
    free(p);
    return head;
}

Node* deleteLast(Node *head){
    Node* p = head;
    Node* q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node* deleteIndex(Node *head,int x){
    if(!x){
        head = deleteFirst(head);
        return head;
    }
    Node* p = head;
    Node* q = head->next;
    for(int i=1 ;i<x; i++){
        p=p->next;
        q=q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

Node* deleteValue(Node *head,int y){
    
    Node* p = head;
    Node* q = head->next;
    while(q->data!=y && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data!=y){
        cout<<"Sorry ! No such value exist\n";
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
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

    cout<<"After deleting first"<<endl;
    head = deleteFirst(head) ; 
    Print(head);
    cout<<endl;

    cout<<"After deleting last"<<endl;
    head = deleteLast(head); 
    Print(head);
    cout<<endl;

    cout<<"Enter index for deleting : ";
    int x;
    cin>>x;
    cout<<"After deleting index"<<endl;
    head = deleteIndex(head,x) ; 
    Print(head);
    cout<<endl;

    cout<<"Enter value for deleting : ";
    int y;
    cin>>y;
    cout<<"After deleting value"<<endl;
    head = deleteValue(head,y) ; 
    Print(head);
    cout<<endl;


    return 0;
}