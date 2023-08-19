/*
    next数组是kmp算法的重要组成部分
    next[i] 表示 字符串前i位中，最长相同前后缀的长度，例如：abbac 为 0 ，abab 为 2
    
    1.初始化next数组，令j=next[0]=-1    字符串下标是从0开始
    2.让i在1-len-1范围内遍历，对每个i执行3，4
    3.不断令j=next[j]，直到j回退为-1，或者s[i]==s[j+1]
    4.如果s[i]==s[j+1]，则next[i]=j+1，否则next[i]=j
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getNext(string s){
    int len = s.length();
    vector<int>next(len);
    int j=-1;
    next[0]=-1;
    for(int i=1;i<len;i++){
        while(j!=-1 && s[i]!=s[j+1]){
            j=next[j];
        } 
        if(s[i]==s[j+1]){
            j++;
        }
        next[i]=j;
    }
    return next;
}

int main(){
    string s;
    cin>>s;
    vector<int>next=getNext(s); 
    for(auto i : next){
        std::cout<<i<<" ";
    }
    std::cout<<endl;
    return 0;
}



/*
    输入样例：
    abababc

    输出样例：
    -1 -1 0 1 2 3 -1 
*/