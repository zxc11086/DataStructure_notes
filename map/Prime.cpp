/*
    prime算法求最小生成树，使用邻接表来储存图
*/

#include<bits/stdc++.h>
#define INF 999999999
using namespace std;

struct node{
    int v,dis;
};

vector<node>Adj[99999];
bool visit[99999];
int d[99999];   //顶点与集合s的最小距离
int vertexs,edges;
set<pair<int,int> >S; //S存放已经访问过的节点,（自动排序
vector<int>routin;

int prime(){
    fill(d,d+99999,INF);
    d[1]=0;
    int ans=0;
    S.insert({0,1});
    for(int i=0;i<vertexs;i++){
        // int u=-1;
        // int MIN=INF;
        // for(int j=1;j<=vertexs;j++){
        //     if(visit[j]==false && d[j]<MIN){
        //         u=j;
        //         MIN=d[j];
        //     }
        // }
        // if(u==-1){
        //     return -1;
        // }
        if(S.size()==0){
            return -1;
        }
        int u = S.begin()->second;    //采用set存储已经访问过的节点，查找最小节点速度更块。
        visit[u]=true;
        ans+=d[u];
        routin.push_back(u);
        S.erase(S.begin());
        for(int j=0;j<Adj[u].size();j++){
            int v=Adj[u][j].v;
            if(visit[v]==false){
                if(Adj[u][j].dis<d[v]){
                    d[v]=Adj[u][j].dis;
                }
                S.insert({d[v],v});
            }
        }
    }
    return ans;

}

int main(){
    cin>>vertexs>>edges;
    for(int i=0;i<edges;i++){
        int l,r,dis;
        node temp;
        cin>>l>>r>>dis;
        temp.v=r;
        temp.dis=dis;
        Adj[l].push_back(temp);
        temp.v=l;
        Adj[r].push_back(temp);  //无向图，两个都要添加
    }
    int res=prime();
    cout<<res<<endl;
    for(auto i : routin){
        cout<<i<<" ";
    }
    cout<<endl;
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


    输出样例：
    4
    1 5 2 4 3
*/