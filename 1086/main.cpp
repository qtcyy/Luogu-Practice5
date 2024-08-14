#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("a.in","r",stdin);
    unordered_map<string,string> mp1,mp2;
    string s,t;
    while (cin.peek() && cin>>s>>t){
        mp1[s]=t;mp2[t]=s;
    }
    while (cin>>s){
        if (mp1.count(s))
            cout<<mp1[s]<<endl;
        else if (mp2.count(s))
            cout<<mp2[s]<<endl;
        else
            cout<<"eh\n";
    }
}