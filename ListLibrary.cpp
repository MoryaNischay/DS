#include <iostream>
using namespace std;
#define show cout<< 
#define take cin>>
#define after ->next
#define space <<" "
#define finl <<endl;
struct Node{
    public:
        int data;
        Node *next;
};                                                              

Node *head=NULL,*tail=NULL;     

//* Create Singly Linked list
void MakeSinglyList(int n){ 
    
    Node *nnode;
    nnode = new Node();
    nnode->data=n;
    nnode->next=NULL;
    if (head==NULL){
        head=nnode;
        tail=nnode;
    }
    else {
        tail->next=nnode;
        tail=tail->next;
    }
};

//* Display Singly Linked list
void OutSinglyList(Node *no){
    Node* OutTemp = no;
    while (OutTemp!=NULL)
    {
        show OutTemp->data<<" ";
        OutTemp=OutTemp->next;
    }
    
}

//* Create a node without a next 
Node* newNodeNoNext(int key){ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

//* Detect A looping Linked List
bool DetectCycle(Node* head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

//* Search your heart out
void searchList(Node* head,int n){
    int count =0;
    if (head==NULL){
        show "List is empty";
    }
    Node* temp = head;
    while (temp!=NULL)
    {
        count++;
        if (n==temp->data){
            show "Element found at " << count;
            break;
            }
        else {
            temp=temp->next;
        }
    }   
}
//* This Doesn't work for some reason so just copy this code and change funny to your start variable
void ReverseList(Node* funny){
    Node* rev;
    rev=funny;
    funny=funny->next;
    rev->next=NULL;
    Node* temp;
    while (funny!=NULL)
    {
        temp=funny;
        funny=funny->next;
        temp->next=rev;
        rev=temp;
    }
    funny=rev;
}
