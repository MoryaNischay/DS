#include <iostream>
using namespace std;
#define show cout<<
#define take cin>>
#define after ->next
#define space <<" "
#define finl <<endl;
#include<stdlib.h>
struct Node{
    public:
        int data;
        Node *next;
};

Node *head=NULL,*tail=NULL;

//* Create Singly Linked list
void MakeSinglyList(int n){

    Node *nnode;
    nnode = new Node();
    nnode->data=n;
    nnode->next=NULL;
    if (head==NULL){
        head=nnode;
        tail=nnode;
    }
    else {
        tail->next=nnode;
        tail=tail->next;
    }
};

//* Display Singly Linked list
void OutSinglyList(Node *no){
    Node* OutTemp = no;
    while (OutTemp!=NULL)
    {
        show OutTemp->data<<" ";
        OutTemp=OutTemp->next;
    }

}

//* Create a node without a next
Node* newNodeNoNext(int key){
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

//* Detect A looping Linked List
bool DetectCycle(Node* head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

//* Search your heart out
void searchList(Node* head,int n){
    int count =0;
    if (head==NULL){
        show "List is empty";
    }
    Node* temp = head;
    while (temp!=NULL)
    {
        count++;
        if (n==temp->data){
            show "Element found at " << count;
            break;
            }
        else {
            temp=temp->next;
        }
    }
}
//* This Doesn't work for some reason so just copy this code and change funny to your start variable
void ReverseList(Node* funny){
    Node* rev;
    rev=funny;
    funny=funny->next;
    rev->next=NULL;
    Node* temp;
    while (funny!=NULL)
    {
        temp=funny;
        funny=funny->next;
        temp->next=rev;
        rev=temp;
    }
    funny=rev;
}

void AddInFront(int number){
	 Node* first = new Node;
	 first->data=number;
	first->next=head;
	head=first;
}

void AddInLast(int last_no){
	Node* last = new Node;
	last->data=last_no;
	Node* temp = head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=last;
	last->next=NULL;
}


void AddAt(int pos,int num){
	Node* nNode = new Node;
	nNode->data=num;
	Node *temp=head;
	for(int i=1;i<pos-1;i++){

	temp=temp->next;
	}
	nNode->next=temp->next;
	temp->next=nNode;
}

void DeleteFirst(){
	Node* garbage = head;
	head=garbage->next;
	free(garbage);
}
void DeleteLast(){
	Node* temp = head;
	Node* temp1= new Node;
	while(temp->next!=NULL){
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
}

void DeleteSpec(int pos){
    Node* nNode = new Node;
	Node *temp=head;
	for(int i=1;i<pos-1;i++){

	temp=temp->next;
	}
	nNode=temp->next;
	temp->next=nNode->next;
	free(nNode);
}

void CountElement(int el){
	Node* temp=head;
	int counter=0;
	while(temp!=NULL){
		if (temp->data==el){
			counter++;
		}
		temp=temp->next;
	}
	show "No. of Times elemnt appeared: "<< counter space;
	
}

void MiddleNode(){
	int count=0;
	Node *temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	int i=count/2;
	if (count%2!=0){
		i++;
	}
	int a=1;
	Node *dump = head;
	while   (a<i){
		a++;
		dump=dump->next;
		
	}
	show "Middle of Node is: " << dump->data;
}
 

//function to delete all the iterations of a number in the list

void del(int key){
    Node *temp=head;
    Node *temp1=head;
    
    while(temp!=NULL){
        if (head->data==key){
            head=head->next;
            free(temp);
            temp=head;
        }
        else if (temp->data==key){
            temp1->next=temp->next;
            free(temp);
            temp=temp1->next;
        }
        else{
            temp1=temp;
            temp=temp->next;
        }
    }
}