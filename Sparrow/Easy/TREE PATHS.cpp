#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define popCount(x) __builtin_popcountll(x)
using namespace __gnu_pbds;
ll MOD = 1e9 + 7;
const int N = 505;
#define el '\n'
#define Peow_peow ios::sync_with_stdio(0), ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
string str[2]={"Left","Right"};

int par[N],numberofnode,target,numberofedge,l,r,p,tar[N];
vector<int>adj[N];

void dfs(int node){
    int co=0;
    for(auto i:adj[node]){
        par[i]=node;
        tar[i]=co;co++;
        dfs(i);
    }
}

void path(int node){
    if(par[node]==0)return;
    path(par[node]);
    if(node==target)cout<<str[tar[node]];
    else cout<<str[tar[node]]<<" ";
}

int arr[N]={0};

int backroot(){
    for(int i=1;i<=numberofnode;i++){
        for(auto j:adj[i])arr[j]++;
    }
    for(int i=1;i<=numberofnode;i++)if(arr[i]==0)return i;
}

int main() {
    cin>>numberofnode>>target>>numberofedge;
    for(int i=0;i<numberofedge;i++){
        cin>>p>>l>>r;
        adj[p].push_back(l);
        adj[p].push_back(r);
    }
    int root=backroot();
    if(root==target){
        cout<<"Root";return 0;
    }
    dfs(root);
    path(target);
    return 0;
}
