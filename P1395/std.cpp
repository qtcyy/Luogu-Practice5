#include "bits/stdc++.h"

#define N 1000001
using namespace std;

int n,u,v,O,vis[N],f[N],g[N],ans;
int k,b[N],first[N],next[N],last[N];//f[i]:以i为根的最大子树的节点数
									//g[i]:以i为根的子树的节点个数
void add(int x,int y)
{
	k++;
	b[k]=y;
	if(first[x]==0)
		first[x]=k;
	else
		next[last[x]]=k;
	last[x]=k;
}

void dfs(int x)
{
	vis[x]=1;
	int p=first[x];
	while(p)
	{
		if(!vis[b[p]])
		{
			dfs(b[p]);
			g[x]+=g[b[p]]+1;
			f[x]=max(f[x],g[b[p]]+1);
		}
		p=next[p];
	}
	f[x]=max(f[x],n-g[x]-1);
	vis[x]=0;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1);
	f[0]=INT_MAX;
	for(int i=1;i<=n;i++)
		if(f[O]>f[i])
			O=i;//树的重心可以有多个,这里取编号最小的一个
	printf("%d ",O);
	memset(g,0,sizeof(g));
	dfs(O);
	for(int i=1;i<=n;i++)
		ans+=g[i];
	printf("%d",ans);
	return 0;
}