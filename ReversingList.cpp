#include "ListLibrary.cpp"
int main(){

    int n;
    show "Enter the number of elements in the linked list " space ;
    take n ;
    show "Enter the Data of the list: " finl

    for(int i=0;i<n;i++){
        int j;
        take j;
        MakeSinglyList(j);
    }
    OutSinglyList(head);
    Node* rev;
    rev=head;
    head=head->next;
    rev->next=NULL;
    Node* temp;
    while (head!=NULL)
    {
        temp=head;
        head=head->next;
        temp->next=rev;
        rev=temp;
        
    }
    head=rev;
    OutSinglyList(head);
}