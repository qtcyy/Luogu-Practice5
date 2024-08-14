#include <bits/stdc++.h>
using namespace std;

struct csys{
    int x,y,z;
};

struct node{
    int s,to,next;
};
node que[100];

void add(int u,int v,int w){

}

int f[100];

inline int find(int x){
    if (f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

signed main(){
    vector<csys> edge;
    for (int i=1;i<100;i++)
        f[i]=i;
    sort(edge.begin(),edge.end(),[](auto p1,auto p2){
        p1.z<p2.z;
    });
    for (auto [x,y,z]:edge){
        int tx=find(x),ty=find(y);
        if (tx!=ty){
            f[tx]=ty;
            add(x,y,z);
            add(y,x,z);
        }
    }

}