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
    int pivotIndex=start-1;
    for (int i=start;i<end;i++){
        if (arr[i]<=pivot){
            pivotIndex++;
            swap(arr[i],arr[pivotIndex]);
        }
    }
    swap(arr[pivotIndex+1],arr[end]);
    return pivotIndex+1;
}

void quickSort(int arr[], int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

void counting_sort(int arr[],int size){
    int max=arr[0];
    for (int i=0;i<size;i++){
        if (arr[i]>max){
            max=arr[i];
        }
    }
    int count[max+1]={0};
    for (int i=0;i<size;i++){
        count[arr[i]]++;
    }
    int j=0;
    for (int i=0;i<max+1;i++){
        while (count[i]>0){
            arr[j]=i;
            j++;
            count[i]--;
        }
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
  
    quickSort(arr,0,5);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}