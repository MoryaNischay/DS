#include <iostream>
using namespace std;
#define show cout<<
#define enter cin>>

void selectionSort(int arr[], int size)
{
    int i, j, min, temp;
    for (i = 0; i < size - 1; i++)
    {
        temp=i;
        for (int j=i+1;j<size;j++){
            if (arr[j]<arr[temp]){
                temp=j;
            }
        }
        int temp2=arr[i];
        arr[i]=arr[temp];
        arr[temp]=temp2;
}}

void bubsort(int arr[],int size){
    int i,j,temp;
    for (int i=0;i<size;i++){
        for (int j=0;j<size-1-i;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

}

void binSearch(int arr[],int size,int key){
    int l=0;
    int h=size;
    int mid = (l+h)/2;
    while (l<=h){
        if (arr[mid]==key){
            show "Found at "<<mid<<endl;
            break;
        }
        else if (arr[mid]>key){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
        mid=(l+h)/2;
    }

}

int main(){
    int size1;
    show "Enter the size of the array: ";
    enter size1;
    int arr1[size1];
    show "Enter the elements of the array: ";
    for (int i=0;i<size1;i++){
        enter arr1[i];
    }
    bubsort(arr1,size1);
    show "The sorted array is: ";
    for (int i=0;i<size1;i++){
        show arr1[i]<<" ";
    }
    int element;
    show "Enter the element to be searched: ";
    enter element;
    binSearch(arr1,size1,element);
     
    return 0;
}