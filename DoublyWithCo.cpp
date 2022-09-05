#include<iostream>
using namespace std;
#define show cout<<
#define take cin>>

struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

struct Node* head = NULL;

struct Node* tail = NULL;

//function to make a doubly linked list 
