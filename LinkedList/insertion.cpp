#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    Node* next; // struct Node* next in c 
};

Node* insertionAtFirst(Node* head , int x)
{ 
    
    // Node* temp = (Node*)malloc(sizeof(Node)); in c
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    return temp; 
}

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

Node* insertionAtEnd(Node* head , int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

        Node* lastnode = head;
        while(lastnode->next!=NULL){
            lastnode = lastnode->next;
        }
        lastnode->next = temp ;
        
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
    cout << "How many numbers?\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number" << endl;
        int x;
        cin >> x;
        head = insertionAtFirst(head,x);
        Print(head);
    }
        cout<<endl;
    
        cout << "Insertion at index is going on " << endl;
        cout << "Enter the place at which you want to insert" << endl;
        int x;
        cin >> x;
        cout << "Enter the data" << endl;
        int data;
        cin >> data;
        head = insertionAtIndex(head,x,data);
        Print(head);
        cout<<endl;
        
        cout << "Insertion at end is going on " << endl;
        int y;
        cin>>y;
        head = insertionAtEnd(head,y);
        Print(head); 

    return 0;
}
