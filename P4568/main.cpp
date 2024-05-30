#include <bits/stdc++.h>
using namespace std;

const int N = 5000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m,k;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void dijkstra(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    dis[s]=0;
    q.emplace(0,s);
    while (!q.empty()){
        int u=q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]>dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                q.emplace(dis[v],v);
            }
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>k;
    int s,t;cin>>s>>t;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
        for (int j=1;j<=k;j++){
            add(u+(j-1)*n,v+j*n,0);
            add(v+(j-1)*n,u+j*n,0);
            add(u+j*n,v+j*n,w);
            add(v+j*n,u+j*n,w);
        }
    }

    for (int i=1;i<=k;i++){
        add(t+(i-1)*n,t+i*n,0);
    }

    dijkstra(s);

    cout<<dis[t+k*n]<<'\n';

    return 0;
}