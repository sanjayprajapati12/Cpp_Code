#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node *next; // struct Node *next in c 
};

bool checkCircular(Node* head){
    
    Node* slow = head ; 
    Node* fast = head ; 

    while(slow!=NULL && fast!=NULL && fast->next!=NULL ){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            if(slow==head)  return true;
            else  return false;
        }
    }
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
    sixth->next = head;

    if(checkCircular(head)) cout<<"This is a circular list\n";
    else cout<<"This is not a circular list\n";
    return 0;
}