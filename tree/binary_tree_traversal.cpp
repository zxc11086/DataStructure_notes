/*
    根据二叉树前序遍历序列输出中序、后序、层次遍历序列
*/

#include<bits/stdc++.h>


struct node{
    char c;
    node* lchild;
    node* rchild;
};

std::string s;
int id;

node* creat(){
    if(s[id]=='#'){
        return NULL;
    }
    node* tree=new node;
    tree->c=s[id];
    id++;
    tree->lchild=creat();
    id++;
    tree->rchild=creat();
    return tree;
}

void lat(node* tree){
    if(tree==NULL){
        return ;
    }
    lat(tree->lchild);
    lat(tree->rchild);
    std::cout<<tree->c;
}

void mid(node* tree){
    if(tree==NULL){
        return ;
    }
    mid(tree->lchild);
    std::cout<<tree->c;
    mid(tree->rchild);
}


void lev(node* tree){
    std::queue<node*>q;
    q.push(tree);
    while(q.size()){
        if(q.front()==NULL){
            q.pop();
            continue;
        }
        std::cout<<q.front()->c;
        q.push(q.front()->lchild);
        q.push(q.front()->rchild);
        q.pop();
    }
}

int main(){
    while(std::cin>>s){
        id=0;
        node* tree;
        tree=creat();
        mid(tree);
        std::cout<<" ";
        lat(tree);
        std::cout<<" ";
        lev(tree);
        std::cout<<std::endl;
    } 
}