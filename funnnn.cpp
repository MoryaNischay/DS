#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;


void DoubleLylist(int value){
    Node* nNode = new Node;
    nNode->data=value;
    nNode->next=NULL;
    nNode->prev=NULL;
    if (head == NULL){
        head=tail=nNode;
    }
    else{
        tail->next=nNode;
        nNode->prev=tail;
        tail=nNode;
    }
}

void AddFront(int newput){
    Node* firstNode = new Node;
    firstNode->data=newput;
    firstNode->next=head;
    head->prev=firstNode;
    head=firstNode;
}

void printDoubly(){
    Node* temp = new Node;
    temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void printBackwards(){
    Node* temp = new Node;
    temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<endl;
}

int main(){
    DoubleLylist(10);
    DoubleLylist(20);
    DoubleLylist(30);
    DoubleLylist(40);
    DoubleLylist(50);
    AddFront(18);
    printDoubly();
    printBackwards(); 
}