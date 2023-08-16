/*
    拓扑排序：判断给定的图是否是有向无环图
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXV=1e5;

vector<int>G[MAXV];
vector<int>ans;

int vertexs,edges;
int inDegree[MAXV];

bool topological_sort(){
    queue<int>q;
    for(int i=1;i<=vertexs;i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }
    int num=0;
    while(q.size()!=0){
        int f=q.front();
        q.pop();
        for(auto i : G[f]){
            inDegree[i]--;
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        ans.push_back(f);
        num++;
    }
    if(num != vertexs){
        return false;
    }
    return true;
}

int main(){
    cin>>vertexs>>edges;
    for(int i=0;i<edges;i++){
        int l,r;
        cin>>l>>r;
        G[l].push_back(r);
        inDegree[r]++;
    }
    bool flag;
    flag=topological_sort();
    if(flag){
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

/*
    测试样例输入1：
    5 7
    1 2
    1 5
    5 3
    3 2
    2 4
    3 4
    2 5

    测试样例输出1：
    -1

    测试样例输入2：
    5 7
    1 2
    2 3
    1 5
    5 3
    3 4
    2 4
    2 5

    测试样例输出2：
    1 2 5 3 4
*/