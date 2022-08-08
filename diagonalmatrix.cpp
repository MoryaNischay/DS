#include <iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the size of the matrix: ";
	cin>>n;
	int d_m[n];
	cout<<"Enter the elements of the matrix: ";
	for (int i=0;i<n;i++){
		cin>>d_m[i];
	}
	int k;
	cout<<"Press 1 to view your array: ";
	cin>>k;
	if (k==1){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i==j){
					cout<<d_m[i];
				}
				else 
					cout<<0;
			}
			cout<<endl;
		}
	}
	
	
	
	}
