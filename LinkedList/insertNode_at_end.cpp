#include <bits/stdc++.h>
#define ll long long
using namespace std;


struct Node
{
    int data;
    Node* next; // struct Node* next in c 
};

Node* insertionAtEnd(Node* head , int x)
{
    // Node* temp = (Node*)malloc(sizeof(Node)); in c
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    // // (*temp).data = x;
    // // (*temp).next = Null;

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
        head = insertionAtEnd(head,x);
        Print(head);
    }
    return 0;
}
