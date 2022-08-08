#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the dimension of array: ";
	cin>>n;
	cout<<"Enter the elements of te diagonal of the array: ";
	int k=3*n-2;
	int t_diag[k];
	for (int i=0;i<k;i++){
		cin>>t_diag[i];
	}
	int temp=0;
	for (int i=0;i<n;i++){
		
		for (int j=0;j<n;j++){
			
			if (i==j){
				cout<<t_diag[temp]<<" ";
				temp++;
			}
			
			else if (i==j-1){
				cout<<t_diag[temp]<<" ";
				temp++;
			}
			else if (i==j+1){
				cout<<t_diag[temp]<<" ";
				temp++;
			}
			else{
				cout<<0<<" ";
			}
			
		}
		cout<<endl;
	}
}
