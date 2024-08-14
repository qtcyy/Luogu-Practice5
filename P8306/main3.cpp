#include <bits/stdc++.h>
using namespace std;

const int N = 3e2+5;

int t,n,q,nxt[N][65],sum[N],cnt=0;
char s[N];

inline int calc(char& x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}

void insert(char s[]){
    int p=0,len=strlen(s);
    for (int i=0;i<len;i++){
        int c=calc(s[i]);
        if (!nxt[p][c]) nxt[p][c]=++cnt;
        p=nxt[p][c];
        sum[p]++;
    }
}

int find(char s[]){
    int p=0,len=strlen(s);
    for (int i=0;i<len;i++){
        int c=calc(s[i]);
        if (!nxt[p][c]) return 0;
        p=nxt[p][c];
    }
    return sum[p];
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>t;
    while (t--){
        for (int i=0;i<=cnt;i++)
            for (int j=0;j<=64;j++)
                nxt[i][j]=0;
        for (int i=0;i<=cnt;i++)
            sum[i]=0;
        cnt=0;
        cin>>n>>q;
        for (int i=1;i<=n;i++){
            cin>>s;
            insert(s);
        }

        for (int i=1;i<=q;i++){
            cin>>s;
            cout<<find(s)<<'\n';
        }
    }

    return 0;
}