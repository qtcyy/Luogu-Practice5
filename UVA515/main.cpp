#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

struct node{
    int s,to,next;
};
node que[N];

int head[105],dis[105];
bool vis[105];
int cnt=1,n,m;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
}

bool spfa(int s){
    memset(dis,-0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    queue<int> q;
    vector<int> sum(105,0);
    q.push(s);
    dis[s]=0;
    sum[s]=1;
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
                    if (++sum[v]>n)
                        return false;
                }
            }
        }
    }
    return true;
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    while (1){
        cin>>n;
        if (!n) return 0;
        cin>>m;
        memset(head,-1,sizeof(head));
        for (int i=1;i<=m;i++){
            int x,y,c;string op;
            cin>>x>>y>>op>>c;
            if (op[0]=='g'){
                add(x-1,x+y,c+1);
            }else{
                add(x+y,x-1,1-c);
            }
        }
        for (int i=1;i<=n;i++)
            add(n+1,i,0);
        if (spfa(n+1))
            puts("lamentable kingdom");
        else
            puts("successful conspiracy");
    }

    return 0;
}