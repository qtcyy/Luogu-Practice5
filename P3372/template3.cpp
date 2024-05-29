#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree{
private:
    vector<ll> tree;
    vector<ll> lazy;
    int n;

    void build(const vector<ll>& arr,int node,int start,int end){
        if (start==end)
            tree[node]=arr[start];
        else{
            int mid=start+end>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
            tree[node]=tree[node<<1]+tree[node<<1|1];
        }
    }

    void spread(int node,int start,int end){
        if (lazy[node]!=0){
            tree[node]+=(end-start+1)*lazy[node];
            if (start!=end){
                lazy[node<<1]+=lazy[node];
                lazy[node<<1|1]+=lazy[node];
            }
            lazy[node]=0;
        }
    }

    void update(int node,int start,int end,int l,int r,ll val){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return;
        if (l<=start && end<=r){
            tree[node]+=(end-start+1)*val;
            if (start!=end){
                lazy[node<<1]+=val;
                lazy[node<<1|1]+=val;
            }
            return;
        }

        int mid=(start+end)>>1;
        update(node<<1,start,mid,l,r,val);
        update(node<<1|1,mid+1,end,l,r,val);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }

    ll query(int node,int start,int end,int l,int r){
        if (start>end || start>r || end<l)
            return 0;
        spread(node,start,end);
        if (l<=start && end<=r)
            return tree[node];

        int mid=start+end>>1;
        ll left=query(node<<1,start,mid,l,r);
        ll right=query(node<<1|1,mid+1,end,l,r);
        return left+right;
    }
public:
    SegmentTree(const vector<ll>& arr){
        n=arr.size()-1;
        tree.resize((n+1)<<2);
        lazy.resize((n+1)<<2);
        build(arr,1,1,n);
    }

    void update(int l,int r,ll val){
        update(1,1,n,l,r,val);
    }

    ll query(int l,int r){
        return query(1,1,n,l,r);
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<ll> arr(n+1);
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (m--){
        int op,x,y;cin>>op>>x>>y;
        if (op==1){
            ll val;cin>>val;
            st.update(x,y,val);
        }else{
            cout<<st.query(x,y)<<endl;
        }
    }

    return 0;
}