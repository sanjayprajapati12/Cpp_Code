#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *next; // struct Node *next in c 
};

bool findLoop(Node* head){
    
    Node* slow = head ; 
    Node* fast = head ; 
    while(slow!=NULL && fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
           return true;
        }
    }
    return false;
}

Node* deleteLoop(Node* head){
    
    Node* slow = head ; 
    Node* start = head->next; 
    Node* fast = head ; 
    while(slow!=NULL && fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            Node* mark1= slow ;
            Node* mark2= slow ->next ;
            while(mark2!=start){
                mark2=mark2->next;
                mark1=mark1->next;
                start=start->next;
            }
            mark1->next = NULL;
            break;
        }
    }

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
    sixth->next = second;

    if(findLoop(head)) cout<<"there is a loop\n";
    else cout<<"there is no loop\n";
    Node* head1 = deleteLoop(head);
    if(findLoop(head1)) cout<<"there is a loop\n";
    else cout<<"there is no loop\n";
    return 0;
}