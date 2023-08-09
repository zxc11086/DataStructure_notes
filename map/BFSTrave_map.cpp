/*
    图的广度优先遍历，采用邻接表存储图
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>Adj[99999];
bool visit[99999];
int vertexs,edegs;

void BFS(int u){
    visit[u]=true;
    queue<int>q;
    q.push(u);
    while(!q.empty()){
        int ft=q.front();
        q.pop();
        for(int i=0;i<Adj[ft].size();i++){
            int v=Adj[ft][i];
            if(visit[v]==false){
                q.push(v);
                visit[v]=true;
            } 
        }
    }
}

void BFSTrave(){
    for(int u=0;u<vertexs;u++){
        if(visit[u]==false){
            BFS(u);
        }
    }
}

int main(){
    cin>>vertexs>>edegs;
    for(int i=0;i<edegs;i++){
        int l,r;
        cin>>l>>r;
        Adj[l].push_back(r);
        Adj[r].push_back(l);
    }
    BFSTrave();
    return 0;
}