#include<iostream>
#include<math.h>
using namespace std;
#define show cout<<
#define take cin>>



void merge(int arr[],int beg,int mid,int end){
    int i,j,k;
    int n1=mid-beg+1;
    int n2=end-mid;
    int left[n1],right[n2];
    for (i=0;i<n1;i++){
        left[i]=arr[beg+i];
    }
    for (j=0;j<n2;j++){
        right[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=beg;

    while (i<n1 && j<n2){
        if (left[i] <= right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int beg,int end){
    if (beg<end){
        int mid =(beg+end)/2;
        mergesort(arr,beg,mid);
        mergesort(arr,mid+1,end);
        merge(arr,beg,mid,end);
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

int main(){
    int arra[20]={44,32,666,123,78,90,8,12,1000,14,69,7,420,33,83,909,9090909,568,889,343};
    int array[7]={ 6,4,8,1,4,3,2};
    display_arr(arra,20);
    mergesort(arra,0,19);
    display_arr(arra,20);
}