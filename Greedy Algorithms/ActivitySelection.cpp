#include <bits/stdc++.h>
using namespace std;

//Activity Selection Problem
//Greedy Algorithm

void activitySelection(vector <int> start,vector <int> finish){
    int n = start.size();
    vector <pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(finish[i],start[i]));
    }
    sort(v.begin(),v.end());
    int i=0;
    cout<<i<<" ";
    for(int j=1;j<n;j++){
        if(v[j].second>=v[i].first){
            i=j;
            cout<<i<<" "<<endl;
        }
    }
}


int main(){
    vector <int> v1{0,1,3,5,5,8};
    vector <int> v2{6,2,4,7,9,9};
    activitySelection(v1,v2);
}