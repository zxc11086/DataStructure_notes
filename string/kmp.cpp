/*
    kmp算法，用于判断一个字符串是否是另一个字符串的子串
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

bool KMP(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    vector<int>next=getNext(pattern); 
    int j=-1;
    for(int i=0;i<n;i++){
        while(j!= -1 && text[i]!=pattern[j+1]){
            j=next[j];
        }
        if(text[i]==pattern[j+1]){
            j++;
        }
        if(j==m-1){
            return true;
        }
    }
    return false;
}

int main(){
    string text,pattern;   //text 为文本串，pattern 为待判断模式串
    cin>>text>>pattern;
    vector<int>next=getNext(text);
    bool res = KMP(text,pattern);
    cout<<res<<endl;
}



/*
    输入样例：
    abababaabc
    ababaab

    输出样例：
    1
*/