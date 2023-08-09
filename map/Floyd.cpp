/*
    弗洛伊德算法，采用邻接矩阵储存图
*/

#include<bits/stdc++.h>
#define INF 999999999
using namespace std;
int vertexs,edges;
int dis[205][205];  //由于Floyd算法的时间复杂度是On3，故数组只要开到200就可以了

void Floyd(){
    for(int k=1;k<=vertexs;k++){    //以k作为中转点，i到j的最短距离
        for(int i=1;i<=vertexs;i++){
            for(int j=1;j<=vertexs;j++){
                if(dis[i][k]!=INF && dis[k][j]!=INF){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
    }
}

int main(){
    cin>>vertexs>>edges;
    fill(dis[0],dis[0]+40005,INF);
    for(int i=1;i<=vertexs;i++){
        dis[i][i]=0;
    }
    for(int i=0;i<edges;i++){
        int l,r,v;
        cin>>l>>r>>v;
        dis[l][r]=v;
    }
    Floyd();
    for(int i=1;i<=vertexs;i++){
        for(int j=1;j<=vertexs;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
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
    0 3 2 3 1
    999999999 0 2 2 1
    999999999 999999999 0 1 999999999
    999999999 999999999 999999999 0 999999999
    999999999 999999999 1 2 0
*/