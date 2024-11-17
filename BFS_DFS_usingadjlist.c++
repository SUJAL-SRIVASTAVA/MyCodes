#include <bits/stdc++.h>
using namespace std;


vector<int> bfstrav(int v , vector<int> adj[]){
    int vis[v]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
    
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}


void dfs(int node, vector<int> adj[], int vis[],vector<int> &ans){
    vis[node]=1;
    ans.push_back(node);
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}

vector<int> dfstrav(int v, vector<int> adj[]){
    int vis[v]={0};
    int start=0;
    vector<int> ans;
    dfs(start,adj,vis,ans);
    return ans;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
