#include <bits/stdc++.h>
#define show cout<<
#define take cin>>

using namespace std;

void solution(){
    int m,n,p;
    take m>>n>>p;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            take a[i][j];
        }
    }
    int ans=0;
    for (int i = 0;i<n;i++){
        int max_column=0;
        for(int j=0;j<m;j++){
            max_column=max(max_column,a[j][i]);
        }
        if (a[p-1][i]<max_column){
            ans+=max_column-a[p-1][i];
        }  
    }
    show ans;
    
}

int main(){
    int t;
    take t;
    for (int i=1;i<=t;i++){
        show "Case #"<<i<<": ";
        solution();
    }
}