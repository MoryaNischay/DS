#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>


void max_heapify(int arr[],int size,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<size && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,size,largest);
    }
}

void build_max_heap(int arr[],int size){
    for (int i=size/2-1;i>=0;i--){
        max_heapify(arr,size,i);
    }
}

void heapsort(int arr[],int size){
    build_max_heap(arr,size);
    for (int i=size-1;i>=0;i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,i,0);
    }
}

int main(){
    int arr[]={17,20,13,12,19,14,11,16,15,18};
    int size=sizeof(arr)/sizeof(arr[0]);
    build_max_heap(arr,size);
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,size);
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
