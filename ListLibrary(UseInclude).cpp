#include <iostream>
using namespace std;
#define show cout<< 
#define take cin>>
class Node{
    public:
        int data;
        Node *next;
};
Node *head=NULL,*tail=NULL;
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

void OutSinglyList(Node *no){
    while (no!=NULL)
    {
        show no->data<<" ";
        no=no->next;
    }
    
}