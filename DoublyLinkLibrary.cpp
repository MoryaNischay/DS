#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

struct Node* head = NULL;

struct Node* tail = NULL;


void MakeDouList(int input) {
   Node* DuoNode = new Node;
   DuoNode->data = input;
   if(tail==NULL){
    head=tail=DuoNode;
    tail->prev=NULL;
   }
   else{
    tail->next=DuoNode;
    DuoNode->prev=tail;
    tail=tail->next;
   }

}

void PrintDuo() {
   struct Node* ptr;
   ptr = head;
   while(ptr->next != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void AddAtStart(int StartData){
   Node* FirstNew = new Node;
   FirstNew->data=StartData;
   FirstNew->next=head;
   head=FirstNew;
   FirstNew->prev=NULL;
}

void AddAtEnd(int EndData){
   Node* EndNew = new Node;
   EndNew->data=EndData;
   Node* temp=head;

   while (temp!=NULL)
   {
      temp=temp->next;
   }
   tail->next=EndNew;
   EndNew->prev=tail;
   
}

void MakeCircle(int circle){
   Node* CircleNew = new Node;
   CircleNew->data=circle;
   if (tail==NULL){
      head=tail=CircleNew;
      tail->next=head;
   }
   else{
      CircleNew->next=tail->next;
      tail->next=CircleNew;
      tail=CircleNew;
   }
}

void InsertRandomCircle(int random,int circle){
   Node* RandomNew = new Node;
   RandomNew->data=circle;
   Node* temp=head;
   for (int i=0;i<random-1;i++){
      temp=temp->next;
   }
   RandomNew->next=temp->next;
   temp->next=RandomNew;
}

void DeleteCircle(int circle){
   Node* temp=head;
   Node* ptr;
   for (int i=0;i<circle-1;i++){
      temp=temp->next;
   }
   ptr=temp->next;
   temp->next=ptr->next;
   free(ptr);
}

void printCircle(){
   if (head==NULL){
      cout<<"Empty List";
   }
   Node* temp = head;
   do {
      cout<<temp->data<<" ";
      temp=temp->next;
   }while(temp!=head);
}

int main() {
   MakeDouList(3);
   MakeDouList(1);
   MakeDouList(7);
   MakeDouList(2);
   MakeDouList(9);
   cout<<"The doubly linked list is: ";
   PrintDuo();
   return 0;
}