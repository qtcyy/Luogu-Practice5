#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+5;

int n,q;

int fa[N];
vector<vector<int>> son;

int siz[N],weight[N],ans[N];

void dfs(int u){
    siz[u]=1;
    ans[u]=u;
    for (int& v:son[u]){
        dfs(v);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],n-siz[v]);
    }
    for (int& v:son[u]){
        int p=ans[v];
        while (p!=u){
            if (max(weight[u],siz[u]-siz[p])<=siz[u]/2){
                ans[u]=p;
                break;
            }
            else
                p=fa[p];
        }
    }
}

signed main(){
    cin>>n>>q;
    son.resize(n+1);
    for (int i=2;i<=n;i++){
        cin>>fa[i];
        son[fa[i]].push_back(i);
    }

    dfs(1);
    while (q--){
        int u;cin>>u;
        cout<<ans[u]<<'\n';
    }

    return 0;
}