#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
vector<int> weight,siz;
int n,minweight=INT_MAX;

void dfs(int u,int fa){
    siz[u]=1;weight[u]=0;
    for (auto& v:edge[u]){
        if (v==fa) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],siz[v]);
    }
    weight[u]=max(weight[u],n-siz[u]);
    minweight=min(minweight,weight[u]);
}

void bfs(int u,int& sum){
    queue<int> q;
    q.push(u);
    vector<bool> vis(n+1,false);
    vector<int> dis(n+1,0);
    while (!q.empty()){
        int u=q.front();q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        sum+=dis[u];
        for (auto& v:edge[u]){
            if (vis[v]) continue;
            q.push(v);
            dis[v]=dis[u]+1;
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    cin>>n;
    edge.resize(n*2+1);
    weight.resize(n+1);
    siz.resize(n+1);
    for (int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1,0);
    int id=n;
    for (int i=n;i>=1;i--)
        if (minweight==weight[i])
            id=i;
    int ans=0;

    bfs(id,ans);
    
    cout<<id<<' '<<ans<<'\n';


    return 0;
}