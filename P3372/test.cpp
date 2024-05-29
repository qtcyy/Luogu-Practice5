#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    vector<int> tree,lazy;
    int n;

    void build(const vector<int>& arr,int node,int start,int end){
        if (start==end)
            tree[node]=arr[start];
        else{
            int mid=start+end>>1;
            build(arr,2*node+1,start,mid);
            build(arr,2*node+2,mid+1,end);
            tree[node]=max(tree[2*node+1],tree[2*node+2]);
        }
    }

    void spread(int node,int start,int end){
        if (lazy[node]!=0){
            tree[node]+=lazy[node];
            if (start!=end){
                lazy[2*node+1]+=lazy[node];
                lazy[2*node+2]+=lazy[node];
            }
            lazy[node]=0;
        }
    }

    void update(int node,int start,int end,int l,int r,int val){
        spread(node,start,end);
        if (start>end || start>r || end<r)
            return;
        if (start>=l && end<=r){
            tree[node]+=val;
            if (start!=end){
                lazy[2*node+1]+=val;
                lazy[2*node+2]+=val;
            }
            return;
        }

        int mid=start+end>>1;
        update(2*node+1,start,mid,l,r,val);
        update(2*node+2,mid+1,end,l,r,val);
        tree[node]=max(tree[2*node+1],tree[2*node+2]);
    }

    int query(int node,int start,int end,int l,int r){
        if (start>end || start>r || end<l)
            return INT_MIN;
        spread(node,start,end);
        if (l<=start && r>=end)
            return tree[node];
        
        int mid=start+end>>1;
        int left=query(2*node+1,start,mid,l,r);
        int right=query(2*node+2,mid+1,end,l,r);
        return max(left,right);
    }
public:
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(n<<2|1);
        lazy.resize(n<<2|1);
        build(arr,0,0,n-1);
    }

    void update(int node,int l,int r,int val){
        update(node,l,r,val);
    }

    int query(int node,int l,int r){
        return query(node,0,n-1,l,r);
    }
};

signed main(){
    // freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,q;cin>>n>>q;
    vector<int> arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (q--){
        int op,l,r;
        cin>>op>>l>>r;
        if (op==1){
            int x;cin>>x;
            l--;r--;
            st.update(0,l,r,x);
        }else{
            cout<<st.query(0,l,r)<<'\n';
        }
    }

    return 0;
}