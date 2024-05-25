#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;

struct extra{
    ll x,y;int e;
};

int f[N];
int n;

inline int find(int x){
    if (f[x]==x) return x;
    return f[x]=find(f[x]);
}

signed main(){
    freopen("b.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while (t--){
        int count=0;
        cin>>n;
        for (int i=1;i<=n*2;i++)
            f[i]=i;
        
        vector<extra> numbers;
        unordered_map<ll,int> mp;

        for (int i=0;i<n;i++){
            ll x,y;int e;cin>>x>>y>>e;
            if (mp.find(x)==mp.end())
                mp[x]=++count;
            if (mp.find(y)==mp.end())
                mp[y]=++count;
            numbers.push_back((extra){x,y,e});
        }
        
        sort(numbers.begin(),numbers.end(),[](const auto& p1,const auto& p2){
            return p1.e>p2.e;
        });

        bool flag=true;
        for (auto& [x,y,e]:numbers){
            x=find(mp[x]),y=find(mp[y]);
            if (e) f[x]=y;
            else{
                if (x==y){
                    flag=false;
                    cout<<"NO\n";
                    break;
                }
            }
        }
        if (flag)
            cout<<"YES\n";
    }

    return 0;
}