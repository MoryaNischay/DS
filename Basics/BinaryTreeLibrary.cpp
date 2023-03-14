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

void postorder(bt_node *temp){
    if (temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        show temp->data << " ";
    }
}

bt_node *search(bt_node *b,int key){
    if (b==NULL){
        return b;
    }

    if (key==b->data){
        return b;
    }

    if (key < b->data){
        return search(b->left,key);
    }

    else {
        return search(b->right,key);
    }

}

bt_node Maximum(bt_node *node){
    while (node->right!=NULL){
        node = node->right;
    }
    return *node;
}

bt_node Minimum(bt_node *node){
    while (node->left!=NULL){
        node=node->left;
    }
    return *node;
}

bt_node *insert(bt_node *n,int key){
    if (n->data==NULL){
        n->data = key;
        return n;
    }
    if (key<n->data){
        n->left = insert (n->left,key);
    }
    else if (key>n->data){
        n->right=insert(n->right,key);
    }
    return n;
}

bt_node treesuc(bt_node *y,bt_node *node){
    if (node->right !=NULL){
        return Minimum(node->right);
    }
    bt_node *succ = NULL;
    while (true){
        if (node->data<y->data){
            succ=y;
            y=y->left;
        }
        else if (node->data>y->data){
            y=y->right;
        }
        else {
            break;
        }
    }
    return *succ;
}

bt_node *deletenode(bt_node *node,int key){
    if (node==NULL){ 
        return node;
    }
    if (key<node->data){
        node->left=deletenode(node->left,key);
    }
    else if (key>node->data){
        node->right=deletenode(node->right,key);
    }
    else {
        if (node->left==NULL){
            bt_node *temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right==NULL){
            bt_node *temp = node->left;
            delete node;
            return temp;
        }
        bt_node temp = treesuc(node,node->right);
        node->data=temp.data;
        node->right=deletenode(node->right,temp.data);
    }
    return node;
}



int main(){
    bt_node *root = NULL;
    root = create();
    show "Inorder: ";
    inorder(root);
}