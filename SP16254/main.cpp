#include <bits/stdc++.h>
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("a.in","r",stdin);
    int t;cin>>t;
    while (t--){
        priority_queue<int,vector<int>,less<int>> a;
        priority_queue<int,vector<int>,greater<int>>b;

        int n;
        while (cin>>n && n){
            if (n==-1){
                cout<<a.top()<<'\n';
                a.pop();
                // continue;
            }
            else if (a.empty() || n<=a.top())
                a.push(n);
            else
                b.push(n);

            if (a.size()>(a.size()+b.size()+1)/2){
                b.push(a.top());
                a.pop();
            }
            else if (a.size()<(a.size()+b.size()+1)/2){
                a.push(b.top());
                b.pop();
            }
        }
    }

    return 0;
}