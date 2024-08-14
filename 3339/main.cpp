#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n;cin>>n;
    map<int,multiset<int,greater<int>>> mp;
    for (int i=1;i<=n;i++){
        string op;cin>>op;
        if (op=="new"){
            int id;cin>>id;
            mp[id]=multiset<int,greater<int>>();
        }else if (op=="add"){
            int id,num;
            cin>>id>>num;
            mp[id].insert(num);
        }else if (op=="merge"){
            int id1,id2;cin>>id1>>id2;
            if (id1!=id2){
                mp[id1].insert(mp[id2].begin(),mp[id2].end());
            }
        }else if (op=="unique"){
            int id;cin>>id;
            unique(mp[id].begin(),mp[id].end());
        }else{
            int id;cin>>id;
            for (const int& p:mp[id])
                cout<<p<<' ';
            cout<<'\n';
        }
    }

    return 0;
}