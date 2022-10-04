#include<iostream>
using namespace std;

class Stack{
    int top;
    int *arr;
    public:
    Stack(int value){
        arr = new int[value];
        top=-1;
        for (int i=0;i<value;i++){
            arr[i]=0;
        }
    }
    bool isEmpty(){
        if (top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if (top==4){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int val){
        if (isFull()){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    int pop(){
        if (isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            int popValue=arr[top];
            arr[top]=0;
            top--;
            return popValue;
        }
    }
    int count(){
        return (top+1);
    }
    int peek(int pos){
        if (isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        else{
            return arr[pos];
        }
    }
    void change(int pos,int val){
        arr[pos]=val;
        cout<<"Value changed at location "<<pos<<endl;
    }
    void display(){
        cout<<"All values in the Stack are"<<endl;
        for (int i=4;i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};

void pushie(Stack s,int value){
    s.push(value);
}

//main function to push values 10 20 30 40 and then display the stack

int main(){
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    pushie(s,50);
    s.display();
}