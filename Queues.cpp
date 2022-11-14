#include <iostream>

using namespace std;
#define show cout<<
#define take cin>>
#define after ->next
#include<stdlib.h>
#define Maxq 100

class Queue{
    int front,rear;
    int* arr;
    public:
    void create(){
        front=rear=-1;
        arr = new int[Maxq];
    }

    bool isEmpty(){
        if (rear==-1){
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull(){
        if (rear==Maxq-1){
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int val){
        if (isFull()){
            show "Queue is full";
        }
        else {
            if (isEmpty()){
                front=rear=0;
            }
            else {
                rear++;
            }
            arr[rear]=val;
        }
    }

    // void display(){
    //     if (isEmpty()){
    //         cout<<"Queue is empty "<<endl;
    //     }
    //     else {
    //         for (int i=0;i<) 
    //     }
    // }

    void dequeue(){
        if (isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else {
            cout<<"Dequeued element is: "<<arr[front]<<endl;
            front++;
        }
    }

    void display(){
        if (isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else {
            for (int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }

    void count(){
        if (isEmpty()){
            show "Queue is empty" <<endl;
        }
        else{
            show "Number of elements in the queue is: "<<rear-front+1<<endl;
        }
    }
    
};

int main(){
    Queue q;
    q.create();
    q.enqueue(2);
    q.enqueue(44);
    q.enqueue(54);
    q.enqueue(33);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
}

