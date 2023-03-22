#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct Node{
    int data;
    Node *next; // struct Node *next in c 
};

int getLength(Node* head){
    int ans = 1;
    Node* p = head ; 
    while(p->next!=NULL){
        ans++;
        p=p->next;
    }
    return ans;
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

    cout<<getLength(head)<<endl;
    return 0;
}