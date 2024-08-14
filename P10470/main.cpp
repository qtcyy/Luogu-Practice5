#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5;

char str[N];

class Trie{
private:
    int nxt[N][26],cnt=0;
    int sum[N];
public:

    void insert(char* s){
        int p=0,len=strlen(s);
        for (int i=0;i<len;i++){
            int c=s[i]-'a';
            if (!nxt[p][c]) nxt[p][c]=++cnt;
            p = nxt[p][c];
        }
        sum[p]++;
    }

    int find(char* s){
        int p=0,len=strlen(s),res=0;
        for (int i=0;i<len;i++){
            int c=s[i]-'a';
            if (!nxt[p][c]) break;
            res+=sum[nxt[p][c]];
            p = nxt[p][c];
        }
        return res;
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    Trie trie;
    for (int i=1;i<=n;i++){
        scanf("%s",str);
        trie.insert(str);
    }
    for (int i=1;i<=m;i++){
        scanf("%s",str);
        printf("%d\n",trie.find(str));
    }

    return 0;
}