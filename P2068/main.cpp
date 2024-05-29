#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree{
private:
    vector<ll> tree;
    int n;

    void build(const vector<int>& arr,int node,int start,int end){
        if (start==end)
            tree[node]=0;
        else{
            int mid=start+end>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
        }
    }

    void update(int node,int start,int end,int idx,ll val){
        if (start==end)
            tree[node]+=val;
        else{
            int mid=start+end>>1;
            if (idx<=mid)
                update(node<<1,start,mid,idx,val);
            else
                update(node<<1|1,mid+1,end,idx,val);
            tree[node]=tree[node<<1]+tree[node<<1|1];
        }
    }

    ll query(int node,int start,int end,int l,int r){
        if (l>end || r<start)
            return 0;
        if (l<=start && r>=end)
            return tree[node];
        ll ans=0;
        int mid=start+end>>1;
        if (l<=mid)
            ans+=query(node<<1,start,mid,l,r);
        if (r>mid)
            ans+=query(node<<1|1,mid+1,end,l,r);
        return ans;
    }
public:
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(n<<2+1);
        build(arr,1,1,n-1);
    }

    void update(int node,int idx,ll val){
        update(node,1,n,idx,val);
    }

    ll query(int node,int l,int r){
        return query(node,1,n,l,r);
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,w;
    cin>>n>>w;
    vector<int> arr(n+1);
    SegmentTree st(arr);
    while (w--){
        char op;int a,b;
        cin>>op>>a>>b;
        if (op=='x'){
            st.update(1,a,b);
        }else{
            cout<<st.query(1,a,b)<<'\n';
        }
    }

    return 0;
}