#include <bits/stdc++.h>
using namespace std;
const int n =4;
bool Safe(int board[n][n],int row,int col){
    int i,j;
    for (i=0;i<col;i++){
        if(board[row][i]==1){
            return false;
        }
    }

    for (i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }

    for (i=row,j=col;i<n && j>=0;i++,j--){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;

}

bool solve(int board[n][n],int col){
    if(col>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(Safe(board,i,col)){
            board[i][col]=1;
            if(solve(board,col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}

int main(){
    int q=4;
    int board[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }
    
    if(solve(board,0)==false){
        cout<<"Solution does not exist";
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}