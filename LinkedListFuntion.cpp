#include<iostream>
using namespace std;

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

void printList(Node *no){
    while (no!=NULL)
    {
        cout<<no->data<<" ";
        no=no->next;
    }
    
}

int main(){
    int n=1;
    int a[20];
    cout<<"Enter the Number of items in Linked List: \t";
    cin>>n;
    cout<<"Enter Data: \t"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        MakeList(a[i]);
    }
    printList(head);
}