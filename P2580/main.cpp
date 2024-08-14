#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
char s[60];
int n,m,ch[N][26],tag[N],tot=1;

void insert(char* s){
    int p=0;
    for (int i=0;s[i];i++){
        int c=s[i]-'a';
        if (!ch[p][c])
            ch[p][c]=tot++;
        p=ch[p][c];
    }
    tag[p]=1;
}

int find(char* s){
    int p=0;
    for (int i=0;s[i];i++){
        int c=s[i]-'a';
        p=ch[p][c];
        if (!p) return -1;
    }
    return p;
}

signed main(){
    freopen("a.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++){
        scanf("%s",s+1);
        insert(s+1);
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        scanf("%s",s+1);
        int p=find(s+1);
        if (p==-1)
            puts("WRONG");
        else if (tag[p]==1){
            puts("OK");
            tag[p]=2;
        }else if (tag[p]==2){
            puts("REPEAT");
        }
    }

    return 0;
}