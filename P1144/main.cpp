#include <bits/stdc++.h>
using namespace std;

const int mod=100003;

vector<vector<int>> edge;

int n,m;

void dijkstra(int s){
    vector<int> dis(n+1,0x3f3f3f3f);
    vector<bool> vis(n+1,false);
    vector<int> sum(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

    dis[s]=0;
    q.emplace(0,s);
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        sum[u]=1;
        for (auto& v:edge[u]){
            if (dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                sum[v]=sum[u];
                q.emplace(dis[v],v);
            }
            else if (dis[v]=dis[u]+1){
                sum[v]+=sum[u];
                sum[v]%=mod;
            }
        }
    }
    for (auto& p:sum)
        cout<<p<<'\n';
    
    return;
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dijkstra(1);


    return 0;
}