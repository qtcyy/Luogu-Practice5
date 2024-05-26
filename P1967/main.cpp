#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int inf = 0x3f3f3f3f;

struct csys{
    int x,y,z;
};
vector<csys> edge;

struct node{
    int s,to,next;
};
node que[N];

int n,m,q;
int head[N],anc[21][N],w[21][N];
bool vis[N];
int cnt=1;
int f[N],deep[N];

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

void dfs(int u){
    vis[u]=1;
    for (int i=head[u];i!=0;i=que[i].next){
        int v=que[i].to;
        if (vis[v]) continue;
        deep[v]=deep[u]+1;
        w[0][v]=que[i].s;
        anc[0][v]=u;
        dfs(v);
    }
}

void kruskal(){
    for (int i=1;i<=n;i++)
        f[i]=i;
    sort(edge.begin(),edge.end(),[&](const auto& p1,const auto& p2){
        return p1.z>p2.z;
    });
    for (auto& [x,y,z]:edge){
        if (find(x)!=find(y)){
            f[find(x)]=find(y);
            add(x,y,z);
            add(y,x,z);
        }
    }
}

inline int lca(int x,int y){
    if (find(x)!=find(y))
        return -1;
    int ans=inf;
    for (int i=20;i>=0;i--)
        if (deep[anc[i][x]]>=deep[y]){
            ans=min(ans,w[i][x]);
            x=anc[i][x];
        }
    if (x==y) return ans;
    for (int i=20;i>=0;i--)
        if (anc[i][x]!=anc[i][y]){
            ans=min(ans,min(w[i][x],w[i][y]));
            x=anc[i][x];y=anc[i][y];
        }
    return min(ans,min(w[0][x],w[0][y]));
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    kruskal();
    for (int i=1;i<=n;i++)
        if (!vis[i]){
            anc[0][i]=0;
            w[0][i]=inf;
            deep[i]=1;
            dfs(i);
        }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++){
            w[i][j]=min(w[i-1][j],w[i-1][anc[i-1][j]]);
            anc[i][j]=anc[i-1][anc[i-1][j]];
        }
    cin>>q;
    while (q--){
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }

    return 0;
}