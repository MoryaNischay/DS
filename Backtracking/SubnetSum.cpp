#include <bits/stdc++.h>
using namespace std;
static int total_calls;

void printsubset(vector<int> subset){
    for(int i=0;i<subset.size();i++){
        if(subset[i]!=0){
            cout<<subset[i]<<" ";
        }
    }
}
//calculate sum of subnets using backtracking
void subsetsum(vector<int> v, vector<int> subset,int v_size,int sub_size,int sum, int ite, int const weight){
    total_calls++;
    if (weight == sum){
        subsetsum(v,subset,v_size,sub_size-1,sum-v[ite],ite+1,weight);
        return;
    }
    else{
        for (int i = ite; i<v_size; i++){
            subset[sub_size] = v[i];
            subsetsum(v,subset,v_size,sub_size+1,sum+v[i],i+1,weight);
        }
    }
}

void generateSubsets(vector<int> v, int weight){
    vector<int> subset;
    subset.resize(v.size());
    subsetsum(v,subset,v.size(),0,0,0,weight);
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
    generateSubsets(v,weight);
    cout<<"Total calls: "<<total_calls<<endl;
    return 0;
    
}