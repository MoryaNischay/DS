#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node * next;
};

int main(){
    node *first=NULL;
    node  *second=NULL;
    node *third=NULL;
    
    first= new node();
    second = new node();
    third= new node();


    first->data=1;
    first->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;
    
    
    while (first!=NULL){
        cout<<first->data<<endl;
        first=first->next;
    }

}