#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n;
    unordered_map<string,int> mp;

    cin>>n;
    vector<string> strs(n);
    for (int i=0;i<n;i++){
        cin>>strs[i];
        mp[strs[i]]++;
    }

    int ans=0,sum=0;
    for (string& str:strs){
        sum=0;
        string tmp="";
        for (char& ch:str){
            tmp+=ch;
            if (mp.count(tmp))
                sum+=mp[tmp];
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;

    return 0;
}