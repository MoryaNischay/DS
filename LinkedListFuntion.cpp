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
    
    show "Linked List: \t";
    OutSinglyList(head);
    show "Enter the number to delete: "<<endl;
    int delkey;
    take delkey;
    del(delkey);
    show "Linked List: \t";
    OutSinglyList(head);
}