#include <bits/stdc++.h>
using namespace std;

struct csys{
    int x,y,z;
};

int n,m,k;
vector<int> f;

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m>>k;
    f.resize(n+1);
    iota(f.begin(),f.end(),0);
    vector<csys> edge;
    for (int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge.push_back({x,y,z});
    }
    sort(edge.begin(),edge.end(),[&](const auto& p1,const auto& p2){
        return p1.z<p2.z;
    });
    int sum=0,count=0;
    for (auto& [x,y,z]:edge){
        x=find(x),y=find(y);
        if (x!=y){
            f[x]=y;
            sum+=z;
            if (++count>=n-k) break;
        }
    }
    if (count>=n-k)
        cout<<sum<<'\n';
    else
        cout<<"No Answer\n";

    return 0;
}