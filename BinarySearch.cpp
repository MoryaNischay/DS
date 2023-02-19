#include<bits/stdc++.h>
using namespace std;

//iterative binary search
int binarySearch(vector<int> v, int n, int key){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(v[mid]==key){
            return mid;
        }
        else if(v[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

//recursive binary search
int recursiveBinarySearch(vector<int> v, int s, int e, int key){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(v[mid]==key){
        return mid;
    }
    else if(v[mid]>key){
        return recursiveBinarySearch(v,s,mid-1,key);
    }
    else{
        return recursiveBinarySearch(v,mid+1,e,key);
    }
}

int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int n = v.size();
    int key;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"Enter the key to be searched:";
    cin>>key;
    // cout<<binarySearch(v,n,key)<<endl;
    cout<<recursiveBinarySearch(v,0,n-1,key)<<endl;
}