/*
    图的最短路径之迪杰斯特拉算法，图采邻接表存储
*/

#include<bits/stdc++.h>
#define INF 999999999
using namespace std;
int vertexs,edges;
bool visit[99999];


struct node{
    int v,dis;  //v表示边的目标顶点，dis为边权
};
vector<node>Adj[99999];
int d[99999]; //起点到各点的最短路径

void Dijkstra(int s){   //s 为起点
    fill(d,d+99999,INF);
    d[s]=0;
    set<pair<int,int> >DIS; //  first表示距离，second表示节点
    DIS.insert({d[s],s});
    for(int i=0;i<vertexs;i++){
        int u=-1,MIN=INF;
        // for(int j=0;j<vertexs;j++){
        //     if(visit[j]==false && d[j]<MIN){
        //         u=j;
        //         MIN=d[j];
        //     }
        // }
        if(DIS.size()==0){
            return ;
        }
        u=DIS.begin()->second;
        visit[u]=true;
        DIS.erase(DIS.begin());
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            if(visit[v]==false){
                if(d[u]+Adj[u][j].dis<d[v]){
                    d[v]=d[u]+Adj[u][j].dis;
                }
                DIS.insert({d[v],v});
            }
        }
    }
}

int main(){
    cin>>vertexs>>edges;
    for(int i=0;i<edges;i++){
        int l,r,dis;
        cin>>l>>r>>dis;
        node temp;
        temp.dis=dis;
        temp.v=r;
        Adj[l].push_back(temp);
    }
    Dijkstra(1);    //这里我们假设以1为七点起点
    for(int i=2;i<=vertexs;i++){
        cout<<d[i]<<endl;
    }
}

/*
    输入样例：
    5  7
    1 2 3
    2 3 4
    2 5 1
    5 3 1
    1 5 1
    2 4 2
    3 4 1

    输出：
    3
    2
    3
    1
*/