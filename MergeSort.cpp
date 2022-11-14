#include<iostream>
using namespace std;

void insertion_sort(int arr[],int size){
    for (int i=0;i<size;i++){
        int temp = arr[i];
        int j=i;
        while(j>0 && arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
    }
}

void shell_sort(int arr[],int size){
    for (int gap=size/2;gap>0;gap/=2){
        for (int i=gap;i<size;i++){
            int temp = arr[i];
            int j;
            for (j=i;j>=gap && arr[j-gap]>temp;j-=gap){
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

void countingsort(int arr[],int size,int max){
    int c[max];
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
    for (int i=size-1;i>=0;i--){
        b[c[arr[i]]] = arr[i];
        c[arr[i]]-=1;
    }
    for (int i=0;i<size;i++){
        arr[i]=b[i+1];
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
  
    countingsort(arr,arr_size,13);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}