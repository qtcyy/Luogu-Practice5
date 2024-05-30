#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m,w;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

bool spfa(int s){
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    queue<int> q;
    vector<int> sum(n+1,0);
    dis[s]=0;
    q.push(s);
    vis[s]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]>dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    if (++sum[v]>n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while (t--){
        memset(head,-1,sizeof(head));
        cin>>n>>m>>w;
        while (m--){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,w);
            add(v,u,w);
        }
        while (w--){
            int u,v,w;
            cin>>u>>v>>w;
            add(u,v,-w);
        }
        cout<<(spfa(1)?"YES\n":"NO\n");
    }

    return 0;
}