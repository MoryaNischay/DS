#include <iostream>

using namespace std;
#define show cout<<
#define take cin>>
#define after ->next
#define space <<" "
#define finl <<endl;
#include<stdlib.h>
#define Maxq 100
struct queue{
    int array[Maxq];
    int front,rear;
};

queue init(){
    queue Q;
    Q.front=Q.rear=-1;
    return Q;
}

int isFull( queue q ){
    return (q.rear==Maxq-1);
}

int isEmpty(queue q ){
    return ((q.front==-1) || (q.front>q.rear));
}

queue enqueue(queue a,int n){
    if (isFull(a)){
        show "Overflow";
    }
    else if (isEmpty(a)){
        a.front=a.rear=0;
        a.array[a.rear]=n;
    }
    else {
        ++a.rear;
        a.array[a.rear]=n;
    }
    return a;
}

queue dequeue(queue b){
    if (isEmpty(b))
    {
        show "UnderFlow";
    }
    else {
        b.front++;
    }
    return b;
}

void print(queue t){
    int i;
    for ( i = t.front; i <=t.rear; i++)
    {
        /* code */
        show t.array[i]<<" ";
    }
    
}

int main(){
    queue Q;
    Q=init();
    Q=enqueue(Q,5);
    Q=enqueue(Q,3);
    Q=enqueue(Q,7);
    Q=enqueue(Q,9);
    Q=enqueue(Q,3);
    Q=enqueue(Q,1);
    show "Current Queue: ";
    print(Q);
}

