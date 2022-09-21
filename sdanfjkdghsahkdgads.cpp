#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Node{
public:
    int val;
    Node *next;
    Node *prev;
};


void inser(Node *root,int v){
    if(root->val==-1){
        root->val=v;
        return;
    }
    Node *temp=new Node();
    temp->val=v;
    Node *p;
    p=root;
    p=root->prev;
    p->next=temp;
    root->prev=temp;
    temp->prev=p;
    temp->next=root;
    
}

void disp(Node* root){
    Node* p;
    p=root;
    Node* q;
    q=p;
    Node* o;
    o=p;
    
    do{
        cout<<p->val<<" ";
        p=p->next;
        if(p->prev!=q){
            q=p;
            o=p->prev;
//            while(p!=q){
//                p=p->prev;
//                cout<<p->val<<" ";
//                cout<<"h";
//            }
            //cout<<o->val<<" ";
           
            p=p->prev->next;
            q=p->prev;
        }
        else
            q=q->next;
        c--;
    }while(c>=0);
}

void cut(Node* root,int x,int y){
    int count=1;
    Node* p;
    p=root;
    Node* q;
    Node* r;
    
    q=root->prev;
    do{
        if(count==x-1)
            q=p;
        if(count==y)
            r=p;
        count++;
        p=p->next;
        c--;
    }while(c>=0);
    p=q->next;
    q->next=r->next;
    r->next->prev=q;
    r->next=p;
    p->prev=r;
    root->prev->next=p;
    root->prev=r;
    q=p;
    p=p->next;
    do{
        p->prev=q;
        p=p->next;
        q=q->next;
    }while(p&&p!=r);
}

void solve()
{
    ll n,m,x,y,i,j,k;
    cin>>n;
    int turn=-1;
    Node *root = new Node();
    root->next=root;
    root->prev=root;
    root->val=-1;
    while(n>=0){
        char func;
        cin>>func;
        if(func=='I'){
            cin>>x;
            inser(root,x);
            if(turn==-1)
                root=root->prev;
            turn*=-1;
        }
        else if(func=='D')
            disp(root);
        else{
            cin>>x>>y;
            cut(root,x,y);
        }
    }
}