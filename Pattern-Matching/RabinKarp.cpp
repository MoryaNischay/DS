#include<bits/stdc++.h>
using namespace std;

int RabinKarp(vector<int> v,vector<int> pat,int d,int q){
    int n = v.size();
    int m = pat.size();
    int h = 1;
    for(int i=0;i<m-1;i++){
        h = (h*d)%q;
    }
    int p = 0;
    int t = 0;
    for(int i=0;i<m;i++){
        p = (p*d + pat[i])%q;
        t = (t*d + v[i])%q;
    }
    for(int i=0;i<=n-m;i++){
        if(p==t){
            int j;
            for(j=0;j<m;j++){
                if(v[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        if(i<n-m){
            t = (d*(t-v[i]*h) + v[i+m])%q;
        }
    }
    return -1;
}

int main(){
    vector<int> v = {1,4,7,1,3,6,9,0,2,5};
    vector<int> pattern = {3,6,9};
    int d = 10;
    int q = 11;
    cout<<RabinKarp(v,pattern,d,q);
    return 0;
}