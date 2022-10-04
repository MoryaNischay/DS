#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		node *prev;
		node(int data)
        {
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};


void insertathead(int val,node* &nnode)
{
	node* n=new node(val);
    
	n->next=nnode;
	if(nnode==NULL)
	{
		nnode=n;	
	}
	else {
        nnode->prev=n;

    }
	nnode=n;
}

void insertattail(int val,node* &nnode)
{
	node* n=new node(val);
	node* temp=nnode;
	
	if(nnode==NULL)
	{
		insertathead(val,nnode);
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
		
	}
	temp->next=n;
	n->prev=temp;	
}

void display(node* nnode)
{
	node* temp=nnode;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node* head=NULL;
	insertattail(90,head);
	insertattail(80,head);
	insertathead(10,head);
	insertathead(20,head);
	insertathead(30,head);
	insertathead(40,head);
	display(head);
}