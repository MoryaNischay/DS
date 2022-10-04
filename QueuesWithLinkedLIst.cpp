#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct Node* front =  NULL;
struct Node* rear = NULL;

void enqueue(int value){
    struct Node *newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL ){
        front = newNode;
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }

}

void dequeue(){
    struct Node *temp;
    temp = front;
    if(front == NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Deleted element is "<<front->data<<endl;
        front = front->next;
        delete temp;
    }
}

void printqueue(){
    struct Node *temp;
    temp = front;
    if(front == NULL){
        cout<<"Queue is empty"<<endl;
    }
    else{
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    cout<<endl;
}



int main(){
    int test_cases;
    cout<<"Enter the number of test cases"<<endl;
    cin>>test_cases;
    for(int i=0;i<test_cases;i++){
        int val;
        cout<<"Enter the value to be inserted"<<endl;
        cin>>val;
        enqueue(val);
    }

    printqueue();
    int dequeue_test_cases;
    cout<<"Enter the number of dequeue test cases"<<endl;
    cin>>dequeue_test_cases;
    for(int i=0;i<dequeue_test_cases;i++){
        dequeue();
    }
    printqueue();
}