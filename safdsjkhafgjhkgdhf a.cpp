#include<iostream>
using namespace std;

struct node{
    int data;
    struct node*prev;
    struct node*next;
};

class DuoList{
public:
    struct node*head;
    struct node*tail;
    bool oneth=true;
    struct node*circle;
    DuoList()
    {
        head = NULL;
        tail = NULL;
        circle = NULL;
    }
    void input_value(int n)
    {
        if(oneth==true)
            AddAtEnd(n);
        else
            append(n);
        oneth = !oneth;

    }
    void AddAtEnd(int n)
    {
        struct node* Nnode = new node;
        Nnode->data = n;
        Nnode->next = NULL;
        Nnode->prev = NULL;
        if(head == NULL)
        {
            head = Nnode;
            tail = Nnode;
        }
        else
        {
            Nnode->next = head;
            head->prev = Nnode;
            head = Nnode;
        }
    }
    void append(int n)
    {
        struct node*Nnode = new node;
        Nnode->data = n;
        Nnode->next = NULL;
        Nnode->prev = NULL;

        if(head == NULL)
        {
            head = Nnode;
            tail = Nnode;
        }
        else
        {
            Nnode->prev = tail;
            tail->next = Nnode;
            tail = Nnode;
        }
    }

    void print(int s)
    
    {   if(s==2){
        int ans;
        struct node*Nnode;
        struct node*prev1;
        Nnode = head;
        while(Nnode!=circle)
        { 
            cout<<Nnode->data<<" ";
            prev1 = Nnode;
            Nnode=Nnode->next;
            
        }
        
        cout << prev1->prev->data <<" " ;
        
    
        
        if(circle != NULL)
        {
            cout<<circle->data<<" ";
            Nnode = tail;
            while(Nnode != circle)
            {
                cout<<Nnode->data<<" ";
                Nnode = Nnode->prev;
            }
            cout<<circle->data<<" ";
        }
        cout<<endl;}
     else{
        int ans;
        struct node*Nnode;
        struct node*prev;
        Nnode = head;
        while(Nnode!=circle)
        { 
            cout<<Nnode->data<<" ";
            prev = Nnode;
            Nnode=Nnode->next;
            
        }
        
        if(circle != NULL)
        {
            cout<<circle->data<<" ";
            Nnode = tail;
            while(Nnode != circle)
            {
                cout<<Nnode->data<<" ";
                Nnode = Nnode->prev;
            }
            cout<<circle->data<<" ";
        }
        cout<<endl;
        }
    }
    void shuffle(int i1, int i2)
    {
        struct node* pos1,* pos2;
        //get nodes
        int i=1;
        struct node* Nnode = head;
        bool is_circle = false;
        while(Nnode != NULL)
        {
            if(i == i1)
                pos1 = Nnode;
            else if(i == i2)
                pos2 = Nnode;
            else if(Nnode == circle)
                is_circle = true;
            if(Nnode == tail)
                break;
            Nnode = Nnode->next;
            i++;
        }
        if(pos1 == head && pos2 == tail)
        {
            tail->next = head;
        }
        if(pos1 == head)
        {
            head = pos2->next;
            head->prev = NULL;
            tail->next = pos1;
            pos1->prev = tail;
            pos2->next = pos1;
            tail = pos2;
        }
        else if(pos2 == tail)
        {
            tail->next = pos1;
        }
        else
        {
            (pos1->prev)->next = pos2->next;
            (pos2->next)->prev = pos1->prev;
            tail->next = pos1;
            pos1->prev = tail;
            pos2->next = pos1;
            tail = pos2;
        }
        circle = pos1;
    }
};
int main()
{   int s = 0;
     char op;
    int temp1, temp2;
    int n;
    cin>>n;
    DuoList* lst = new DuoList();
    for(int i=0;i<n;i++)
    {
        cin>>op;
        if(op == 'I')
        {
            cin>>temp1;
            lst->input_value(temp1);
        }
        else if(op == 'D')
        
        {   
            
            lst->print(s);
        }
        else if(op == 'S')
         {  s++;
            cin>>temp1>>temp2;
            lst->shuffle(temp1, temp2);
        }
        else if(op == 'F')
        {
            cout<<lst->head->data<<endl;
        }
    }
    
    
}