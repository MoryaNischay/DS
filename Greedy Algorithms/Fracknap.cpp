#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int> a,pair<int,int> b){
    double r1=(double)a.first/a.second;
    double r2=(double)b.first/b.second;
    return r1>r2;
}

int fractionknap(vector <pair<int,int>> v,int weight){
    sort(v.begin(),v.end(),cmp);
    int currweight=0;
    double finalvalue=0.0;
    for(int i=0;i<v.size();i++){
        if(currweight+v[i].second<=weight){
            currweight+=v[i].second;
            finalvalue+=v[i].first;
        }
        else{
            int remain=weight-currweight;
            finalvalue+=v[i].first*((double)remain/v[i].second);
            break;
        }
    }
    return finalvalue;
}

int main(){
    int W=50;
    vector <pair<int,int>> v{{60,10},{100,20},{120,30}};
    cout<<fractionknap(v,W);

}