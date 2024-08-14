#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    vector<vector<int>> nxt;
    vector<int> sum;
    int cnt;

    int calc(char c){
        if (c>='a' && c<='z'){
            return c-'a'+26;
        }else if (c>='A' && c<='Z'){
            return c-'A';
        }else{
            return c-'0'+52;
        }
    }
public:
    Trie(): nxt(3000005,vector<int>(65,0)), sum(3000005), cnt(0) {};

    void insert(string& s){
        int p=0;
        for (char& ch: s){
            int c=calc(ch);
            if (!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
            sum[p]++;
        }
    }

    int find(string& s){
        int p=0;
        for (char& ch: s){
            int c = calc(ch);
            if (!nxt[p][c]) return 0;
            p = nxt[p][c];
        }
        return sum[p];
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int T;cin>>T;
    string s;
    while (T--){
        int n,q;
        cin>>n>>q;
        
        Trie trie;
        for (int i=1;i<=n;i++){
            cin>>s;
            trie.insert(s);
        }
        while (q--){
            cin>>s;
            cout<<trie.find(s)<<'\n';
        }
    }

    return 0;
}