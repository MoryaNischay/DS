#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,vector<string> &board,int n){
    for (int i=0;i<col;i++){
        if (board[row][i]=='Q'){
            return false;
        }
    }
    for (int i=row,j=col;i>=0 && j>=0;i--,j--){
        if (board[i][j]=='Q'){
            return false;
        }
    }
    for (int i=row,j=col;i<n && j>=0;i++,j--){
        if (board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}

void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
    if (col==n){
        ans.push_back(board);
        return;
    }
    for (int row=0;row<n;row++){
        if (isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for (int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}

int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  vector < vector < string >> ans = solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
