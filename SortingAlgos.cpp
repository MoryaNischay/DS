#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>
#define endl <<endl

void selection_sort(int arr[], int size){

    for(int i=0;i<size;i++){
        int min=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        if (min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    
}


int main(){

}