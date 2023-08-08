/*
    根据前序遍历序列构造二叉树，并求其深度
    by zxc
    2023-08-05 15:44
*/


#include<bits/stdc++.h>

//节点定义
struct node{
    char c;
    node* lchild;
    node* rchild;
};

//前序遍历序列
std::string s;
//当前下标
int id;


//递归构造二叉树
node* creat(){
    node* root;
    if(s[id]=='#'){
        root=NULL;
        return root;
    }
    root = new node;
    root->c=s[id];
    id++;
    root->lchild=creat();
    id++;
    root->rchild=creat();
    return root;
}


//递归求深度
int deep(node* tree){
    if(!tree){
        return 0;
    }
    return std::max(deep(tree->lchild),deep(tree->rchild))+1;
}



int main(){
    int t;
    std::cin>>t;
    while(t--){
        std::cin>>s;
        node* tree;
        id=0;
        tree=creat();
        std::cout<<deep(tree)<<std::endl;
    }
    return 0;
}