#include<iostream>
#include<math.h>
using namespace std;
#define show cout<<
#define take cin>>

//function to create linked list

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *temp,*ptr;
    int n;
    show "Enter the number of nodes";
    take n;
    for(int i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        show "Enter the data";
        take temp->data;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            ptr=head;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
    }
    return head;
}