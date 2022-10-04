#include<iostream>
using namespace std;
#define show cout<<
#define get cin>>
struct Node {
   int data;
   
   struct Node *next;
};


struct Node* head = NULL;


void push(int value){
    Node* NewNode = new Node;
    NewNode->data = value;
    NewNode->next = NULL;
    if (head==NULL){
        head=NewNode;
    }
    else{
        NewNode->next = head;
        head=NewNode;
    }
}

void pop(){
    if (head==NULL){
        show "Stack is empty";
    }
    else {
        Node* temp = head;
        show "Popped element is " << temp->data<<endl;
        head = head->next;
        delete temp;
    }
}


int main(){
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    
}