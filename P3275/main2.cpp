#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N];
bool vis[N];
int cnt=1,n,k;
bool flag=false;

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
            if (dis[v]<dis[u]+que[i].s){
                dis[v]=dis[u]+que[i].s;
                if (!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    if (++sum[v]>=n){
                        flag=true;
                        return;
                    }
                }
            }
        }
    }
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&k);
    while (k--){
        int op,a,b;
        scanf("%d%d%d",&op,&a,&b);
        if (op==1){
            add(a,b,0);add(b,a,0);
        }else if (op==2){
            add(a,b,1);
        }else if (op==3){
            add(b,a,0);
        }else if (op==4){
            add(b,a,1);
        }else{
            add(a,b,0);
        }
    }
    for (int i=1;i<=n;i++)
        add(0,i,1);
    spfa(0);
    if (flag){
        puts("-1");
    }else{
        long long ans=0;
        for (int i=1;i<=n;i++)
            ans+=1ll*dis[i];
        printf("%lld\n",ans);
    }

    return 0;
}