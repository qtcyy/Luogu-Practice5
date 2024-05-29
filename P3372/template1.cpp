#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr,int node,int start,int end){
        if (start==end)
            tree[node]=arr[start];
        else{
            int mid=start+end>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
            tree[node]=tree[node<<1]+tree[node<<1|1];
        }
    }

    void update(int node,int start,int end,int idx,int val){
        if (start==end)
            tree[node]=val;
        else{
            int mid=(start+end)>>1;
            if (idx<=mid)
                update(node<<1,start,mid,idx,val);
            else
                update(node<<1|1,mid+1,end,idx,val);
            tree[node]=tree[node<<1]+tree[node<<1|1];
        }
    }

    int query(int node,int start,int end,int l,int r){
        if (l>end || r<start)
            return 0;
        if (l<=start && end<=r)
            return tree[node];
        int mid=start+end>>1;
        int ans=0;
        ans+=query(node<<1,start,mid,l,r);
        ans+=query(node<<1|1,mid+1,end,l,r);
        return ans;
    }
public:
    SegmentTree(const vector<int>& arr){
        n=arr.size()-1;
        tree.resize(n<<2);
        build(arr,1,1,n);
    }

    void update(int idx,int val){
        update(1,1,n,idx,val);
    }

    int query(int l,int r){
        return query(1,1,n,l,r);
    }
};

signed main(){
    freopen("b.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n+1);
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (q--){
        int op;cin>>op;
        if (op==0){
            int idx,val;cin>>idx>>val;
            st.update(idx,val);
        }else{
            int l,r;cin>>l>>r;
            cout<<st.query(l,r)<<'\n';
        }   
    }

    return 0;
}