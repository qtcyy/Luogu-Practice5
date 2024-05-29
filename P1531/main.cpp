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
            build(arr,(node<<1)+1,start,mid);
            build(arr,(node<<1)+2,mid+1,end);
            tree[node]=max(tree[(node<<1)+1],tree[(node<<1)+2]);
        }
    }

    void update(int node,int start,int end,int idx,int val){
        if (start==end)
            tree[node]=val;
        else{
            int mid=(start+end)>>1;
            if (idx<=mid)
                update((node<<1)+1,start,mid,idx,val);
            else
                update((node<<1)+2,mid+1,end,idx,val);
            tree[node]=max(tree[(node<<1)+1],tree[(node<<1)+2]);
        }
    }

    int query(int node,int start,int end,int l,int r){
        if (r<start || l>end)
            return INT_MIN;
        if (l<=start && r>=end)
            return tree[node];
        int mid=(start+end)>>1;
        int left=query((node<<1)+1,start,mid,l,r);
        int right=query((node<<1)+2,mid+1,end,l,r);
        return max(left,right);
    }
public:
    SegmentTree(const vector<int>& arr){
        n=arr.size();
        tree.resize(n<<2);
        build(arr,0,0,n-1);
    }

    void update(int idx,int val){
        update(0,0,n-1,idx,val);
    }

    int queryMax(int l,int r){
        int result=query(0,0,n-1,l,r);
        return result;
    }
};

signed main(){
    freopen("a.in","r",stdin);
    cin.tie(0)->sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for (int i=0;i<n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (q--){
        char op;
        int a,b;
        cin>>op>>a>>b;
        a--;
        if (op=='U' && arr[a]<b){
            st.update(a,b);
        }else if (op=='Q'){
            b--;
            cout<<st.queryMax(a,b)<<'\n';
        }
    }

    return 0;
}