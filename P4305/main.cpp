#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        unordered_set<int> st;
        vector<int> ans;
        for (int i=0;i<n;i++){
            int x;
            cin>>x;
            if (st.find(x)==st.end())
                ans.push_back(x);
            
            st.insert(x);
        }
        for (int& p:ans)
            cout<<p<<' ';
        
        cout<<'\n';
    }

    return 0;
}