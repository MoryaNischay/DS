#include<iostream>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};


struct Node* head = NULL;
struct Node* tail= NULL;

void push(int value){
    Node* StackNode = new Node;
    StackNode->data=value;
    StackNode->next=NULL;
    StackNode->prev=NULL;
    if (head==NULL){
        head=tail=StackNode;
    }
    else{
        tail->next=StackNode;
        StackNode->prev=tail;
        tail=tail->next;
    }
}

void pop(){
    Node* ptr;
    ptr=tail;
    if (tail==NULL){
        cout<<"Stack underflow"<<endl;
    }
    else {
        cout<<"POPed element is "<<ptr->data<<endl;
        tail=tail->prev;
        delete ptr;
    }
}

void displayStack(){
    Node* temp;
    temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}



int main(){
    push(1);
    pop();
    pop();
    
}