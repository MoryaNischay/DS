#include "ListLibrary.cpp"

int main(){
    int no_items;
    int ListArray[20];
    show "Enter the Number of items in Linked List: \t";
    take no_items;
    show "Enter Data: \t"<<endl;
    for(int i=0;i<no_items;i++){
        take ListArray[i];
    }
    for(int i=0;i<no_items;i++){
        MakeSinglyList(ListArray[i]);
    }
    
    OutSinglyList(head);
    ReverseList (head);
    OutSinglyList(head);
}