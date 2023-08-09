/*
    简单无向图的深度优先遍历
    采用邻接表存储
*/
#include<bits/stdc++.h>
using namespace std;
int vertexs,edges;
vector<int>Adj[99999];  //图的邻接表,大小为节点个数
bool visit[99999];   //这里开到vertexs的大小就行，用来记录节点有没有被访问


void DFS(int u,int depth){
    visit[u]=true;
    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(visit[v]==false){
            DFS(v,depth+1);
        }
    }
}

void DFSTrave(){
    for(int u=1;u<=vertexs;u++){
        if(visit[u]==false){
            DFS(u,1);
        }
    }
}


int main(){
    cin>>vertexs>>edges;
    for(int i=0;i<edges;i++){
        int l,r;
        cin>>l>>r;
        Adj[l].push_back(r);
        Adj[r].push_back(l);
    }
    DFSTrave();
}