#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};

class Node* newNode(int data){
    Node* node = new Node;
    node ->data=data;
    node ->next=NULL;
    return node;
}

void makeList(Node** root,int data){
    
}