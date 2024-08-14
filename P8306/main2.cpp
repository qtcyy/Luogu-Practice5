#include <bits/stdc++.h>
using namespace std;

class Trie{
private:
    int nxt[30005][65],cnt=0;
    int sum[30005];

    inline int calc(char ch){
        if (ch>='A' && ch<='Z')
            return ch-'A';
        else if (ch>='a' && ch<='z')
            return ch-'a'+26;
        else
            return ch-'0'+52;
    }
public:
    void init(){
        memset(nxt,0,sizeof(nxt));
        memset(sum,0,sizeof(sum));
        cnt=0;
    }

    void insert(char* s){
        int p=0;
        for (int i=0;i<strlen(s);i++){
            int c = calc(s[i]);
            if (!nxt[p][c]) nxt[p][c]=++cnt;
            p = nxt[p][c];
            sum[p]++;
        }
    }

    int find(char* s){
        int p = 0;
        for (int i=0;i<strlen(s);i++){
            int c=calc(s[i]);
            if (!nxt[p][c]) return 0;
            p = nxt[p][c];
        }
        return sum[p];
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int T;scanf("%d",&T);
    Trie trie;
    int n,m;char s[30005];
    while (T--){
        trie.init();
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++){
            scanf("%s",s);
            trie.insert(s);
        }
        for (int i=1;i<=m;i++){
            scanf("%s",s);
            printf("%d\n",trie.find(s));
        }
    }

    return 0;
}