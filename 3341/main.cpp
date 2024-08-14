#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("a.in","r",stdin);
    unordered_set<int> st;
    unordered_multiset<int> st2;
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        string op;int x;
        cin>>op>>x;
        if (op=="add"){
            st.insert(x);
            st2.insert(x);
            cout<<st2.count(x)<<'\n';
        }else if (op=="del"){
            cout<<st2.count(x)<<'\n';
            st2.erase(x);
        }else{
            if (st.count(x))
                cout<<1<<' ';
            else
                cout<<0<<' ';
            cout<<st2.count(x)<<'\n';
        }
    }

    return 0;
}