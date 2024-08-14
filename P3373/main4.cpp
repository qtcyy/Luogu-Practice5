#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree{
private:
    vector<ll> tree;
    vector<ll> lazyAdd,lazyMul;
    int n;ll mod;

    void build(const vector<ll>& arr,int node,int start,int end){
        if (start==end){
            tree[node]=arr[start];
        }else{
            int mid=(start+end)>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
            tree[node]=(tree[node<<1]+tree[node<<1|1])%mod;
        }
    }

    void spread(int node,int start,int end){
        if (lazyMul[node]!=1){
            tree[node] = (tree[node]*lazyMul[node])%mod;
            if (start!=end){
                lazyMul[node<<1]=(lazyMul[node<<1]*lazyMul[node])%mod;
                lazyMul[node<<1|1]=(lazyMul[node<<1|1]*lazyMul[node])%mod;
                lazyAdd[node<<1]=(lazyAdd[node<<1]*lazyMul[node])%mod;
                lazyAdd[node<<1|1]=(lazyAdd[node<<1|1]*lazyMul[node])%mod;
            }
            lazyMul[node]=1;
        }
        if (lazyAdd[node]!=0){
            tree[node]=(tree[node]+(end-start+1)*(lazyAdd[node]))%mod;
            if (start!=end){
                lazyAdd[node<<1]=(lazyAdd[node<<1]+lazyAdd[node])%mod;
                lazyAdd[node<<1|1]=(lazyAdd[node<<1|1]+lazyAdd[node])%mod;
            }
            lazyAdd[node]=0;
        }
    }

    void updateAdd(int node,int start,int end,int l,int r,ll val){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return;
        if (l<=start && end<=r){
            lazyAdd[node]=(lazyAdd[node]+val)%mod;
            spread(node,start,end);
            return;
        }
        int mid=(start+end)>>1;
        updateAdd(node<<1,start,mid,l,r,val);
        updateAdd(node<<1|1,mid+1,end,l,r,val);
        tree[node]=(tree[node<<1]+tree[node<<1|1])%mod;
    }

    void updateMul(int node,int start,int end,int l,int r,ll val){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return;
        if (l<=start && end<=r){
            lazyMul[node]=(lazyMul[node]*val)%mod;
            spread(node,start,end);
            return;
        }
        int mid=(start+end)>>1;
        updateMul(node<<1,start,mid,l,r,val);
        updateMul(node<<1|1,mid+1,end,l,r,val);
        tree[node]=(tree[node<<1]+tree[node<<1|1])%mod;
    }

    ll query(int node,int start,int end,int l,int r){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return 0;
        if (l<=start && end<=r)
            return tree[node];
        int mid=(start+end)>>1;
        ll left=query(node<<1,start,mid,l,r);
        ll right=query(node<<1|1,mid+1,end,l,r);
        return (left+right)%mod;
    }
public:
    SegmentTree(const vector<ll>& arr,ll m){
        n=arr.size();
        mod=m;
        tree.resize(n<<2);
        lazyMul.resize(n<<2,1);
        lazyAdd.resize(n<<2,0);
        build(arr,1,1,n);
    }

    void updateAdd(int l,int r,ll val){
        updateAdd(1,1,n,l,r,val);
    }

    void updateMul(int l,int r,ll val){
        updateMul(1,1,n,l,r,val);
    }

    ll query(int l,int r){
        return query(1,1,n,l,r);
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,q,m;
    cin>>n>>q>>m;
    vector<ll> arr(n+1);
    for (int i=1;i<=n;i++){
        cin>>arr[i];
    }
    SegmentTree st(arr,m);
    while (q--){
        int op,x,y;
        cin>>op>>x>>y;
        if (op==1){
            ll val;
            cin>>val;
            st.updateMul(x,y,val);
        }else if (op==2){
            ll val;
            cin>>val;
            st.updateAdd(x,y,val);
        }else{
            cout<<st.query(x,y)<<'\n';
        }
    }

    return 0;
}