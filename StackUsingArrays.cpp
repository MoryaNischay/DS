#include<iostream>
using namespace std;

class Stack{
    int top;
    int size;
    int* arr;
    public:
    void create(int size){
        top=-1;
        arr=new int[size];
        this->size=size;
    }

    bool isFull(){
        if (top==size-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(int val){
        if (top==size-1){
            cout<<"Stack is full"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }

    bool isEmpty(){
        if (top==-1){
            return true;
        }
        else {
            return false;
        }
    }

    void pop(){
        if (isEmpty()){
            cout<<"Underflow"<<endl;
        }
        else {
            cout<<"Popped element is: "<<arr[top]<<endl;
            top--;
        }
    }

    void display(){
        for (int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
//main function to push values 10 20 30 40 and then display the stack

int main(){
    Stack s;
    s.create(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.push(20);
    s.push(30);
    s.push(909);
    s.pop();
    s.pop();
    s.display();
}