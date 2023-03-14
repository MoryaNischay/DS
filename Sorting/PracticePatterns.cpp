#include<bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>

void display_arr(int arr[],int size){
    for (int i=0;i<size;i++){
        cout<<arr[i];
        if(i==size-1){
            break;
        }
        else {
            cout<<" , ";
        }
    }
    cout<<endl;
}

int partition(int arr[],int start,int end){
    int pIndex=start-1;
    int pivot=arr[end];
    for (int i=start;i<end;i++){
        if (arr[i]<=pivot){
            pIndex++;
            swap(arr[i],arr[pIndex]);
        }
    }
    swap(arr[pIndex+1],arr[end]);
    return pIndex+1;
}

void quickSort(int arr[],int start,int end){
    if (start>end){
        return;
    }
    int p=partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
}

int main(){
    int arra[20]={44,32,666,123,78,90,8,12,1000,14,69,7,420,33,83,909,9090909,568,889,343};
    int array[7]={ 6,4,8,1,4,3,2};
    display_arr(arra,20);
    quickSort(arra,0,20);
    display_arr(arra,20);
}