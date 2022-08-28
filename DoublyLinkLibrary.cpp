#include <iostream>
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