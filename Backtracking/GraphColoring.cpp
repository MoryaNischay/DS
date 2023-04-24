#include<bits/stdc++.h>
using namespace std;

#define V 4

bool isSafe(bool graph[V][V], int color[]){
    for (int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            if(graph[i][j] && color[i]==color[j])
                return false;
        }
    }
    return true;
}

bool graphcoloring(bool graph[V][V], int m, int i, int color[]){
    if(i==V){
        if(isSafe(graph,color))
            return true;
        return false;
    }
    for(int j=1;j<=m;j++){
        color[i]=j;
        if(graphcoloring(graph,m,i+1,color))
            return true;
        color[i]=0;
    }
    return false;
}

int main(){
    bool graph[V][V] = {{0, 1, 1, 1},
                        {1, 0, 1, 0},
                        {1, 1, 0, 1},
                        {1, 0, 1, 0},
                       };
    int m = 3; 
    int color[V];
    for (int i=0; i<V; i++)
       color[i] = 0;
    if(!graphcoloring(graph,m,0,color))
        cout<<"No solution";
    else{
        for(int i=0;i<V;i++)
            cout<<color[i]<<" ";
    }
    return 0;

}