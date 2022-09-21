#include <iostream>
using namespace std;

struct node{
	node *prev;
	int val;
	node *next;
} *head, *tail ,*circle= NULL;

void PrintDuo(int cn){
    node *display = head;

			for(int k=0;k<cn;k++){
				cout << display->val << " " ;
				display = display->next;
			}
			if(tail->next!=NULL){
				cout << display->val << " " ;
			}
			cout << endl;
}

void AddatEnd(node *nnode){
    node* NewNode = new node;
    NewNode=nnode;
    NewNode->next = head;
					head->prev = NewNode;
					head = head->prev;
					head->prev = NULL;
}

void AddAtFront(node* nnode){
    node* NewNode = new node;
    tail->next = NewNode;
	NewNode->prev = tail;
	tail = tail->next;
	tail->next = NULL;
}

void shuffle(int i1, int i2)
    {
        node *Nnode=new node;
        struct node* pos1,* pos2;
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
    }


int main(){
	int n,count=0; 
	cin >> n;
	int i =0;
	while(n--){
		char ch;
		cin >> ch;

		if(ch=='I'){
			int x;
			cin >> x;
			node *NewNode = new node;
			NewNode->val = x;

			if(head==NULL && tail==NULL){
				NewNode->prev = NULL;
				NewNode->next = NULL;
				head = NewNode;
				tail = NewNode;
			} else{
				if(i%2!=0){
					// add to the front of the list
                    AddAtFront(NewNode);
				} else{
					// add to the back of the head
					AddatEnd(NewNode);
				}
			}
            
			count++;


		}
        
		if(ch=='D'){
			// display tbe linked list
			PrintDuo(count);
		}
        if(ch=='D'){
			int a,b;
            cin>>a>>b;
            shuffle(a,b);

		}
		i++;
	}



	return 0;
}