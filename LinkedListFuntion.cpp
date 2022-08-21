#include<iostream>
using namespace std;
#define show cout<< 
#define take cin>>
class Node{
    public:
        int data;
        Node *next;
};
Node *head=NULL,*tail=NULL;
void MakeList(int n){
    
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

void OutList(Node *no){
    while (no!=NULL)
    {
        show no->data<<" ";
        no=no->next;
    }
    
}

int main(){
    int no_items;
    int ListArray[20];
    show "Enter the Number of items in Linked List: \t";
    take no_items;
    show "Enter Data: \t"<<endl;
    for(int i=0;i<no_items;i++){
        take ListArray[i];
    }
    for(int i=0;i<no_items;i++){
        MakeList(ListArray[i]);
    }
    OutList(head);
}