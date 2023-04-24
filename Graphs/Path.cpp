#include <bits/stdc++.h>
using namespace std;
#define NODE 4

int graph[NODE][NODE] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};

int tempGraph[NODE][NODE];

int findStartvert(){
    for (int i=0;i<NODE;i++){
        int deg=0;
        for (int j=0;j<NODE;j++){
            if(tempGraph[i][j]==1){
                deg++;
            }
        }
        if (deg%2==1){
            return i;
        }
    }
    return 0;
}

int dfs(int prev,int start,bool visited[]){
    int count=1;
    visited[start]=true;
    for (int u=0;u<NODE;u++){
        if (prev!=u){
            if (tempGraph[start][u]==1){
                if (visited[u]==false){
                    count+=dfs(start,u,visited);
                }
            }
        }
    }
    return count;
}

bool isBridge(int u,int v){
    int deg = 0;
    for (int i=0;i<NODE;i++){
        if (tempGraph[v][i]==1){
            deg++;
        }
    }
    if(deg>1){
        return false;
    }
    return true;
}

int edgeCount(){
    int count=0;
    for (int i=0;i<NODE;i++){
        for (int j=0;j<NODE;j++){
            if (tempGraph[i][j]==1){
                count++;
            }
        }
    }
    return count;
}

void fleury(int start){
    static int edge = edgeCount();
    static int v_count = NODE;
    for (int v=0;v<NODE;v++){
        if (tempGraph[start][v]){
            bool visited[NODE]={false};
            if (isBridge(start,v)){
                v_count--;
            }
            int count = dfs(start,v,visited);
            if (abs(v_count-count)<=2){
                cout<<start<<"-"<<v<<" ";
                if (isBridge(v,start)){
                    v_count--;
                }
                tempGraph[start][v]=tempGraph[v][start]=0;
                edge--;
                fleury(v);
            }
        }
    }
}
int main(){
    for (int i=0;i<NODE;i++){
        for (int j=0;j<NODE;j++){
            tempGraph[i][j]=graph[i][j];
        }
    }
    cout<<"Eulerian Path: ";
    fleury(findStartvert());
}