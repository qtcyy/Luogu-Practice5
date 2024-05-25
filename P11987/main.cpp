#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int f[N*2],siz[N],sum[N];
int n,m;

inline void init(){
    for (int i=1;i<=n;i++){
        f[i]=i+n;
        f[i+n]=i+n;
        siz[i+n]=i;
        sum[i+n]=1;
    }
}

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

void merge(int x,int y){
    x=find(x);y=find(y);
    if (x!=y){
        f[x]=y;
        siz[y]+=siz[x];
        sum[y]+=sum[x];
    }
}

void move(int x,int y){
    int tx=find(x),ty=find(y);
    if (tx!=ty){
        f[x]=ty;
        siz[tx]-=x,siz[ty]+=x;
        sum[tx]--;sum[ty]++;
    }
}

inline void getans(int s){
    int fa=find(s);
    cout<<sum[fa]<<' '<<siz[fa]<<'\n';
}

signed main(){
    freopen("a.in","r",stdin);
    while (cin>>n>>m){
        init();
        while (m--){
            int op,p,q;
            cin>>op>>p;
            if (op==1){
                cin>>q;
                merge(p,q);
            }
            else if (op==2){
                cin>>q;
                move(p,q);
            }
            else
                getans(p);
        }
    }
}