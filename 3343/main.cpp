#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n;cin>>n;
    multiset<pair<int,int>, greater<pair<int,int>> > st;
    st.emplace(1,1000000000);
    for (int i=1;i<=n;i++){
        int id,val;cin>>id>>val;
        auto it = st.lower_bound(make_pair(val,0));
        
    }

}