#include <bits/stdc++.h>
using namespace std;

//huffman coding

struct node{
    char data;
    int freq;
    node *left;
    node *right;
    node(char data,int freq){
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

struct compare{
    bool operator()(node *l,node *r){
        return l->freq>r->freq;
    }
};

void print(node *root,string str){
    if(!root)
        return;
    if(root->data!='$')
        cout<<root->data<<" : "<<str<<endl;
    print(root->left,str+"0");
    print(root->right,str+"1");
}

void huffman(string s,int freq[],int n){
    node *left,*right,*top;
    priority_queue<node*,vector<node*>,compare> minheap;
    for(int i=0;i<n;i++){
        minheap.push(new node(s[i],freq[i]));
    }
    while(minheap.size()!=1){
        left=minheap.top();
        minheap.pop();
        right=minheap.top();
        minheap.pop();
        top=new node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        minheap.push(top);
    }
    print(minheap.top(),"");
}

int main(){
    string s="abcdef";
    int freq[]={5,9,12,13,16,45};
    int n=s.length();
    huffman(s,freq,n);
}