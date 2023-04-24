#include <bits/stdc++.h>
using namespace std;
static int total_calls;

void GetSubset(int weight,int ind,int sum,vector<int> &arr,int N,vector<int> &sumSubset){
    if (sum==weight){
        for (auto i:sumSubset){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if (ind==N){
        return;
    }
    GetSubset
(weight,ind+1,sum+arr[ind],arr,N,sumSubset);
    GetSubset
(weight,ind+1,sum,arr,N,sumSubset);

}
void subsetSums(vector<int> arr, int N, int sum)
{
    vector<int> sumSubset;
    GetSubset
(sum,0,0,arr,N,sumSubset);
    for (int i=0;i<sumSubset.size();i++){
        cout<<sumSubset[i]<<" ";
    }
}


int main(){
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int weight = 12;
    //print the vector and the weight we are trying to get
    cout<<"The vector is: ";
    for (auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"The weight is: "<<weight<<endl;
    int n = v.size();
    
}