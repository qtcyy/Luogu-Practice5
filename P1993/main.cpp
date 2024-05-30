#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,m;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

void spfa(int s){
    memset(dis,-0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    queue<int> q;
    dis[0]=0;
    vis[0]=1;
    q.push(0);
    vector<int> sum(n+1,0);
    while (!q.empty()){
        int u=q.front();q.pop();
        vis[u]=0;
        for (int i=head[u];i!=-1;i=que[i].next){
            int v=que[i].to;
            if (dis[v]<dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    if (++sum[v]>=n){
                        puts("No");
                        return;
                    }
                }
            }
        }
    }
    puts("Yes");
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n>>m;
    while (m--){
        int op,a,b;
        cin>>op>>a>>b;
        if (op==1){
            int c;cin>>c;
            add(b,a,c);
        }else if (op==2){
            int c;cin>>c;
            add(a,b,-c);
        }else{
            add(a,b,0);
            add(b,a,0);
        }
    }
    for (int i=1;i<=n;i++)
        add(0,i,0);
    spfa(0);

    return 0;
}