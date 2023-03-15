#include<bits/stdc++.h>
using namespace std;

#define show cout<<
#define take cin>>

int rec(int n,vector<int> dp){
    if (n<=1){
        return n;
    }
    if (dp[n]!=-1) return dp[n];
    return dp[n]=rec(n-1,dp)+rec(n-2,dp);
}

int better(int n,vector<int> dp){
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<dp.size();i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int evenbetter(int n){
    int prev=0;
    int prev2=1;
    for (int i=2;i<n+1;i++){
        int temp=prev+prev2;
        prev=prev2;
        prev2=temp;
    }
    return prev2;
}

int main(){
    int a;
    show "Enter a value: ";
    take a;
    vector<int> dp(a+1,-1);
    show evenbetter(a);
}