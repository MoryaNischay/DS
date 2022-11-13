#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>



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

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start-1;
    for (int i=start;i<end;i++){
        if (arr[i]<=pivot){
            pIndex++;
            swap(arr[i],arr[pIndex]);
        }
    }
    swap(arr[pIndex+1],arr[end]);
    return pIndex+1;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

void countingsort(int arr[],int size, int max){
    int c[size];
    for (int i=0;i<=max;i++){
        c[i]=0;
    }
    for (int i=0;i<size;i++){
        c[arr[i]]+=1;
    }
    for (int i=1;i<=max;i++){
        c[i]=c[i]+c[i-1];
    }
    int b[size];
    for (int i= size-1;i>=0;i--){
        b[c[arr[i]]]=arr[i];
        c[arr[i]]-=1;
    }
    for (int i=0;i<size;i++){
        arr[i]=b[i+1];
    }
}

int main(){
    int arra[20]={44,32,666,123,78,90,8,12,1000,14,69,7,420,33,83,909,9090909,568,889,343};
    int array[7]={ 6,4,8,1,4,3,2};
    display_arr(array,7);
    countingsort(array,7,8);
    display_arr(array,7);
}