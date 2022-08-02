#include<iostream>
using namespace std;
class Array{
	public:
	int position,ins;
	int n=0;
	int arr[7]={1,2,3,4,5,6,7};
	void create_arr(){
		
		cout<<"Enter the size of the array: "<<endl;
		cin>>n;
		cout<<"Enter the components of the array"<<endl; 
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
	}
	void display_arr(){
		cout<<"Your array is: "<<endl;
		if (n!=0){
			for (int i=0;i<n;i++){
				cout<<arr[i];
			}
		}
		if (n==0){
			for (int i=0;i<5;i++){
				cout<<arr[i];
			}
		}
	}
	void insert_arr(){
		cout<<"Enter the position to insert in: ";
		cin>>position;
		cout<<"Enter the number to be inserted: ";
		cin>>ins;
		n=n+1;
		for (int i = n; i >= position; i--){
	
        	arr[i] = arr[i - 1];}
    
    	arr[position - 1] = ins;
 
    	
	}
	void del_arr(){
		int del;
		cout<<"Enter the position you want to delete from: "<<endl;
		cin>>del;
		for (int i=del-1;i<n;i++){
			arr[i]=arr[i+1];
			n=n-1;
		}

	}
	void search(){
		int sh,elem_pos;
		cout<<"Enter the element you want to search: ";
		cin>>sh;
		for (int i=0;i<n;i++){
			if (arr[i]==sh){
				elem_pos=i+1;
				break;
			}
		}
		cout<<"Your Element was found at "<<elem_pos<< " position"<<endl;
	}
};
int main(){
	int a,b,c;
	Array ob;
	cout<<"-----MENU-----"<<endl;
	cout<<"1.CREATE"<<endl;
	cout<<"2.DISPLAY"<<endl;
	cout<<"3.INSERT"<<endl;
	cout<<"4.DELETE"<<endl;
	cout<<"5.SEARCH"<<endl;
	cout<<"6.EXIT"<<endl;
	cin>>a;
	if (a<=0 || a>6){
		cout<<"Not a valid input";
	}
	else{
		switch(a){
			case 1:
				ob.create_arr();			
		
			case 2:
				ob.display_arr();
			
			}
		}
	cin>>b;
	if (b==3){
		
			ob.insert_arr();
			ob.display_arr();
	}
	cin>>c;
	if (c==4){
		ob.del_arr();
		ob.display_arr();
	}
}
