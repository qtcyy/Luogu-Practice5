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
            int mid=(start+end)>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
            tree[node]=min(tree[node<<1],tree[node<<1|1]);
        }
    }

    int query(int node,int start,int end,int l,int r){
        if (l>end || r<start)
            return INT_MAX;
        if (l<=start && r>=end)
            return tree[node];
        int mid=(start+end)>>1;
        int left=query(node<<1,start,mid,l,r);
        int right=query(node<<1|1,mid+1,end,l,r);
        return min(left,right);
    }
public:
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(n<<4+1);
        build(arr,1,1,n);
    }

    int query(int node,int l,int r){
        return query(node,1,n,l,r);
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1);
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (m--){
        int l,r;cin>>l>>r;
        cout<<st.query(1,l,r)<<' ';
    }
    cout<<'\n';

    return 0;
}