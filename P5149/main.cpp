#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

map<string,int> mp;
ll ans=0;
string s;
int n,a[N],b[N];

void merge_sort(int left,int right){
    if (left>=right) return;
    int mid=(right-left)/2+left;
    merge_sort(left,mid);
    merge_sort(mid+1,right);
    int i=left, j=mid+1,k=left;
    while (i<=mid && j<=right){
        if (a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++]=a[j++], ans+=mid-i+1;
    }
    while (i<=mid)
        b[k++]=a[i++];
    while (j<=right)
        b[k++]=a[j++];
    for (int i=left;i<=right;i++)
        a[i]=b[i];
}

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s;
        mp[s]=i;
    }
    for (int i=1;i<=n;i++){
        cin>>s;
        a[mp[s]]=i;
    }
    merge_sort(1,n);
    cout<<ans<<'\n';

    return 0;
}