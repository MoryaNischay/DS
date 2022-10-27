#include<iostream>
#include<string>
#define show cout<<
#define take cin>>
using namespace std;

struct bt_node{
    int data;
    bt_node *left;
    bt_node *right;
};


bt_node *create(){
    bt_node* newNode = new bt_node;
    show "Enter data: ";
    take newNode->data;
    if (newNode->data == -1){
        return NULL;
    }
    show "Enter left child of " << newNode->data << ": ";
    newNode->left = create();
    show "Enter right child of " << newNode->data<<" : ";
    newNode->right = create();
    return newNode;
}

void preorder(bt_node *temp){
    if (temp!=NULL){
        show temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(bt_node *temp){
	if (temp!=NULL){
		inorder(temp->left);
		show temp->data << " ";
		inorder(temp->right);
	}
}