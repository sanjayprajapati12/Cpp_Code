#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Node
{
    int data;
    Node* next; // struct Node* next in c 
};

Node* insertionAtIndex(Node* head , int x , int data)
{
    Node* temp = new Node();
    Node* p = head;
    for(int i=1 ;i<x ;i++ ){
        p= p->next;
    }
    temp->data = data;
    temp->next = p->next;
    p->next = temp; 

    return head;
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
    Node* head = NULL; //empty list
    Node *first = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *forth = new Node();

    first->data = 10;
    second->data = 20;
    third->data = 30;
    forth->data = 40;
    
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    Print(head);
      
        cout << "Enter the place at which you want to insert" << endl;
        int x;
        cin >> x;
        cout << "Enter the data" << endl;
        int data;
        cin >> data;
        head = insertionAtIndex(head,x,data);
        Print(head);
    return 0;
}
