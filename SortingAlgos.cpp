#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

void selection_sort(int arr[],int size){
    int min;
    for (int i=0;i<size-1;i++){
        min=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }
        if (min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

void display_arr(int arr[],int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" , ";
    }
    cout<<endl;
}

void insertionsort(int arr[],int size){
    for (int i=0;i<size;i++){
        int temp=arr[i];
        int j=i;
        while (j>>0 && arr[j-1]>temp)
        {
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

void bubblesort(int arr[],int size){
    for (int i=0;i<size;i++){
        for (int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void shellsort(int arr[],int n){
    for (int gap = n/2;gap>0;gap/=2){
        for (int i=gap;i<n;i++){
            int temp=arr[i];
            int j;
            for ( j=i;j>=gap && arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];

            }
            arr[j]=temp;
        }
    }
}

int main(){
    int array[20]={44,32,666,123,78,90,8,12,1000,14,69,7,420,33,83,909,9090909,568,889,343};
    display_arr(array,20);
    shellsort(array,20);
    display_arr(array,20);
}