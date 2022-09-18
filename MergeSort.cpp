#include<iostream>
using namespace std;

void merge(int array[],int beg,int mid,int end){
    int i,j,k;
    int n1= mid-beg+1;  //size of left subarray
    int n2 = end-mid;   //size of right subarray

    int left[n1],right[n2]; //temp arrays

    for (i = 0; i < n1; i++)
    {
        left[i] = array[beg+i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = array[mid+1+j];
    }

    i=0;
    j=0;
    k=beg;

    while (i<n1 && j<n2)
    {
        if (left[i]<=right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int a[],int beg,int end){
    if (beg<end)
    {
        int mid = (beg+end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,beg,mid,end);
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
  
    mergeSort(arr, 0, arr_size - 1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}