#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;

struct node{
    int s,to,next;
};
node que[N];

int head[N],dis[N],sum[N];
bool vis[N],flag=0;
int cnt=1,n,m;

inline void add(int u,int v,int w){
    que[cnt].s=w;
    que[cnt].to=v;
    que[cnt].next=head[u];
    head[u]=cnt++;
    return;
}

void spfa(int x){
    memset(dis,0,sizeof(dis));
    queue<int>q;
    q.push(x);
    dis[x]=0;
    vis[x]=1;
    while (!q.empty()){
        int u=q.front();
        q.pop();
        sum[u]++;
        vis[u]=false;
        if (sum[u]==n){
            printf("-1\n");
            flag=1;
            exit(0);
        }
        for (int i=head[u];i!=-1;i=que[i].next){
            int k=que[i].to;
            if (dis[k]<dis[u]+que[i].s){
                dis[k]=dis[u]+que[i].s;
                if (!vis[k]){
                    vis[k]=true;
                    q.push(k);
                }
            }
        }
    }
}

int main(void){
    freopen("a.in","r",stdin);
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int x,a,b;
        scanf("%d%d%d",&x,&a,&b);
        if (x==1){
            add(a,b,0);
            add(b,a,0);
        }
        else if (x==2){
            if (a==b)
                {printf("-1\n");return 0;}
            add(a,b,1);
        }
        else if (x==3)
            add(b,a,0);
        else if (x==4){
            if (a==b)
                {printf("-1\n");return 0;}
            add(b,a,1);
        }
        else{
            add(a,b,0);
        }
    }
    for (int i=n;i>=1;i--)
        add(0,i,1);
    spfa(0);
    if (flag)
        return 0;
    LL ans=0;
    for (int i=1;i<=n;i++)
        ans+=(LL)dis[i];
    printf("%lld\n",ans);

    return 0;
}