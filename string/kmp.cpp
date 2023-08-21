/*
    kmp算法，用于判断一个字符串是否是另一个字符串的子串
    1.初始化j=-1，表示pattern当前已被匹配的最后位置
    2.让i遍历文本串text，对每个i，执行3，4来是试图匹配text[i]和pattern[j+1]
    3.不断令j=next[j],直到j回退到-1，或者text[i]==pattern[j+1]
    4.如果text[i]==pattern[j+1],则j++，如果j==m-1，则说明pattern使text的字串
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> getNext(string s){  //求next数组
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

bool KMP(string text,string pattern){   //kmp算法
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