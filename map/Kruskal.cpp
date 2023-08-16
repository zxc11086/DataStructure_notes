/*
    kuruskal算法解决最小生成树问题  <!--边贪心 --!>
    1.对所有边按照边权从小到大排序
    2.按边权从小到大测试所有边，若当前测试边所连接的两个顶点不在同一个联通块内，则将这条测试边加入到联通块，否则，舍弃
    3.重复2，直到测试完所有边
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXE = 1e5;

struct edge{
    int l,r;
    int cost;
}E[MAXE];

bool cmp(edge a,edge b){
    return a.cost<b.cost;
}

int father[MAXE];   //并查集数组

int findFather(int x){
    int a=x;
    while(x!=father[x]){
        x=father[x];
    } 
    //路径压缩
    while(a!=father[x]){
        int z=a;
        a=father[x];
        father[z]=x;
    }
    return x;
}

int kruskal (int vertexs,int edges){
    int ans=0;
    //初始化并查集
    for(int i=0;i<vertexs;i++){
        father[i]=i;
    }
    //开始枚举所有边
    int nums=0; //已添加的边的数量
    for(int i=0;i<edges;i++){
        int fl=findFather(E[i].l);
        int fr=findFather(E[i].r);
        if(fl != fr){
            father[fl]=fr;
            ans+=E[i].cost;
            nums++;
        }
        if(nums>=vertexs-1){
            break; 
        }
    }
    return ans;
}
    

int main(){
    int vertexs,edges;
    cin>>vertexs>>edges;
    for(int i=0;i<edges;i++){
        int l,r,cost;
        cin>>l>>r>>cost;
        E[i].l=l;
        E[i].r=r;
        E[i].cost=cost;
    } 
    sort(E,E+edges,cmp);
    int ans=kruskal(vertexs,edges); 
    std::cout<<ans<<std::endl;
    return 0;
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
*/