#include <bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int graph[V][V], int src, int dest){
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<V;i++){
            if(visited[i]==false && graph[u][i]>0){
                q.push(i);
                parent[i]=u;
                visited[i]=true;
            }
        }
    }
    return (visited[dest]==true);
}

int fordFulkerson(int graph[V][V], int src, int dest){
    int u,v;
    int max_flow=0;
    int rGraph[V][V];
    int parent[V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            rGraph[i][j]=graph[i][j];
        }
    }
    while(bfs(rGraph,src,dest)){
        int path_flow=INT_MAX;
        for(v=dest;v!=src;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }
        for(v=dest;v!=src;v=parent[v]){
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}

int main(){
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
    cout<<fordFulkerson(graph,0,5);
    return 0;
}