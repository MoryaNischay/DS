#include<bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>

void print1(int n){
    for (int i=0;i<n;i++){
        int counter=0;
        for(int j=0;j<i+1;j++){
            counter++;
            cout<<counter%2<<" ";
            
        }
        cout<<endl;
    }
}

int main(){
    int n;
    n=5;
    print1(n);
}