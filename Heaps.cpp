#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>

class heap{
    public: 
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        //Time complexity is O(logn)
        size ++;
        int index=size;    
        arr[size]=val;
        
        while(index>1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
            }
            else {
                return;
            }
        }
    }

    void deletefromheap(){
        //Time complexity is O(logn)
        int index=1;
        arr[index]=arr[size];
        size--;
        while(index<size){
            int left = 2*index;
            int right = 2*index+1;
            if(arr[index]<arr[left] || arr[index]<arr[right]){
                if(arr[left]>arr[right]){
                    swap(arr[index],arr[left]);
                    index=left;
                }
                else{
                    swap(arr[index],arr[right]);
                    index=right;
                }
            }
            else{
                return;
            }
        }
        
    }

    void print(){
        for(int i=1;i<=size;i++){
            show arr[i]<<" ";
        }
    }
};

void heapify(vector<int> vec,int size){
    int largest=size;
    int left = 2*size;
    int right = 2*size+1;

    if (left<vec.size() && vec[left]>vec[largest]){
        largest=left;
    }

    if (right<vec.size() && vec[right]>vec[largest]){
        largest=right;
    }

    if (largest!=size){
        swap(vec[largest],vec[size]);
        heapify(vec,largest);
    }
    for (int i=1;i<vec.size();i++){
        show vec[i]<<" ";
    }
}

int main(){
    heap h;
    h.insert(88);
    h.insert(55);
    h.insert(50);
    h.insert(44);
    h.insert(9);
    h.deletefromheap();
    vector<int> vec1;   
    vec1.push_back(-1);
    vec1.push_back(88);
    vec1.push_back(55);
    vec1.push_back(50);
    vec1.push_back(44);
    vec1.push_back(9);
    heapify(vec1,5);
    
}