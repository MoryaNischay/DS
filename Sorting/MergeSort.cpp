#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    vector<int> temp;
    while(i<=mid && j<=e){
        if(v[i]<v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(v[j]);
        j++;
    }
    int k = 0;
    for (int i = s; i <= e; i++)
    {
        v[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> &v, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,e);
}

int main(){
    //unsorted array of random numbers
    vector<int> v{123,41,2154,16134,8674,2345,3456,54,234,512};
    int n = v.size();
    int key;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
}
//Iterative Merge Sort

// #include <bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int l, int m, int r);
// int min(int x, int y) { return (x<y)? x :y; }


// void mergeSort(int arr[], int n)
// {
// int curr_size; // For current size of subarrays to be merged
// 				// curr_size varies from 1 to n/2
// int left_start; // For picking starting index of left subarray
// 				// to be merged

// // Merge subarrays in bottom up manner. First merge subarrays of
// // size 1 to create sorted subarrays of size 2, then merge subarrays
// // of size 2 to create sorted subarrays of size 4, and so on.
// for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
// {
// 	// Pick starting point of different subarrays of current size
// 	for (left_start=0; left_start<n-1; left_start += 2*curr_size)
// 	{
// 		// Find ending point of left subarray. mid+1 is starting
// 		// point of right
// 		int mid = min(left_start + curr_size - 1, n-1);

// 		int right_end = min(left_start + 2*curr_size - 1, n-1);


// 		merge(arr, left_start, mid, right_end);
// 	}
// }
// }

// /* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
// void merge(int arr[], int l, int m, int r)
// {
// 	int i, j, k;
// 	int n1 = m - l + 1;
// 	int n2 = r - m;

// 	/* create temp arrays */
// 	int L[n1], R[n2];

// 	/* Copy data to temp arrays L[] and R[] */
// 	for (i = 0; i < n1; i++)
// 		L[i] = arr[l + i];
// 	for (j = 0; j < n2; j++)
// 		R[j] = arr[m + 1+ j];

// 	/* Merge the temp arrays back into arr[l..r]*/
// 	i = 0;
// 	j = 0;
// 	k = l;
// 	while (i < n1 && j < n2)
// 	{
// 		if (L[i] <= R[j])
// 		{
// 			arr[k] = L[i];
// 			i++;
// 		}
// 		else
// 		{
// 			arr[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}

// 	/* Copy the remaining elements of L[], if there are any */
// 	while (i < n1)
// 	{
// 		arr[k] = L[i];
// 		i++;
// 		k++;
// 	}

// 	/* Copy the remaining elements of R[], if there are any */
// 	while (j < n2)
// 	{
// 		arr[k] = R[j];
// 		j++;
// 		k++;
// 	}
// }


// void printArray(int A[], int size)
// {
// 	int i;
// 	for (i=0; i < size; i++)
// 		cout <<" "<< A[i];
// 	cout <<"\n";
// }

// int main()
// {
// 	int arr[] = {12, 11, 13, 5, 6, 7};
// 	int n = sizeof(arr)/sizeof(arr[0]);

// 	cout <<"Given array is \n ";
// 	printArray(arr, n);

// 	mergeSort(arr, n);

// 	cout <<"\nSorted array is \n ";
// 	printArray(arr, n);
// 	return 0;
// }
