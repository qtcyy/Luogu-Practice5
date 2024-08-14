#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    vector<int> tree;
    vector<int> lazyAdd,lazyMul;
    int n,mod;

    void build(const vector<int>& arr,int node,int start,int end){
        if (start==end){
            tree[node]=arr[start];
        }else{
            int mid=(start+end)>>1;
            build(arr,node<<1,start,mid);
            build(arr,node<<1|1,mid+1,end);
            tree[node]=tree[node<<1]+tree[node<<1|1];
        }
    }

    void spread(int node,int start,int end){
        if (lazyMul[node]!=1){
            tree[node] *= lazyMul[node];
            if (start!=end){
                lazyMul[node<<1] *= lazyMul[node];
                lazyMul[node<<1|1] *= lazyMul[node];
                lazyAdd[node<<1] *= lazyMul[node];
                lazyAdd[node<<1|1] *= lazyMul[node];
            }
            lazyMul[node]=1;
        }
        if (lazyAdd[node]!=0){
            tree[node] += (end-start+1)*lazyAdd[node];
            if (start!=end){
                lazyAdd[node<<1]+=lazyAdd[node];
                lazyAdd[node<<1|1]+=lazyAdd[node];
            }
            lazyAdd[node]=0;
        }
    }

    void updateAdd(int node,int start,int end,int l,int r,int val){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return;
        if (l<=start && end<=r){
            lazyAdd[node]+=val;
            spread(node,start,end);
            return;
        }
        int mid=(start+end)>>1;
        updateAdd(node<<1,start,mid,l,r,val);
        updateAdd(node<<1|1,mid+1,end,l,r,val);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }

    void updateMul(int node,int start,int end,int l,int r,int val){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return;
        if (l<=start && end<=r){
            lazyMul[node] *= val;
            spread(node,start,end);
            return;
        }
        int mid=(start+end)>>1;
        updateMul(node<<1,start,mid,l,r,val);
        updateMul(node<<1|1,mid+1,end,l,r,val);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }

    int query(int node,int start,int end,int l,int r){
        spread(node,start,end);
        if (start>end || start>r || end<l)
            return 0;
        if (l<=start && end<=r)
            return tree[node];
        int mid=(start+end)>>1;
        int left=query(node<<1,start,mid,l,r);
        int right=query(node<<1|1,mid+1,end,l,r);
        return left+right;
    }
public:
    SegmentTree (const vector<int>& arr){
        n=arr.size();
        tree.resize(n<<2);
        lazyAdd.resize(n<<2,0);
        lazyMul.resize(n<<2,1);
        build(arr,1,1,n);
    }

    void updateAdd(int l,int r,int val){
        updateAdd(1,1,n,l,r,val);
    }

    void updateMul(int l,int r,int val){
        updateMul(1,1,n,l,r,val);
    }

    int query(int l,int r){
        return query(1,1,n,l,r);
    }
};

signed main(){
    freopen("a.in","r",stdin);
    int n,q,m;
    cin>>n>>q>>m;
    vector<int> arr(n+1);
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    SegmentTree st(arr);
    while (q--){
        int op,x,y;
        cin>>op>>x>>y;
        if (op==1){
            int val;cin>>val;
            st.updateMul(x,y,val);
        }else if (op==2){
            int val;cin>>val;
            st.updateAdd(x,y,val);
        }else{
            cout<<st.query(x,y)<<endl;
        }
    }

    return 0;
}