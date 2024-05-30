#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int v,w,next;
}e[2005];
int cnt,head[105];
int dis[105],tot[105];//tot为如队次数 
bool vis[105],flag;
queue<int>q;
void init()//初始化 
{
	cnt=0;
	flag=0;
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(e));
	memset(dis,-0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(tot,0,sizeof(tot));
}
void add(int u,int v,int w)
{
	++cnt;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void spfa()
{
	dis[n+1]=0;
	vis[n+1]=1;
	tot[n+1]=1;
	q.push(n+1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=e[i].next)
		{
			int v=e[i].v,w=e[i].w;
			if(dis[v]<dis[x]+w)
			{
				dis[v]=dis[x]+w;
				if(!vis[v])
				{
					vis[v]=1;
					++tot[v];
					q.push(v) ;
					if(tot[v]>n)//有环 
					{
						cout<<"successful conspiracy";//无解 
						flag=1;
						break;
					}
				}
			}
		}
		if(flag)break;
	}
}
int main()
{
    freopen("a.in","r",stdin);
	while(1)
	{
		cin>>n;
		if(!n)return 0;
		cin>>m;
		init();
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			string ch;
			cin>>u>>v>>ch>>w;
			if(ch=="gt")
			{
				add(u-1,u+v,w+1);
			}
			else 
			{
				add(u+v,u-1,1-w);
			}
		}
		for(int i=1;i<=n;i++)add(n+1,i,0); //超级原点 
		spfa();
		if(!flag)cout<<"lamentable kingdom";
		cout<<endl;
	}
} 