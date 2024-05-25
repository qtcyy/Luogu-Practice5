#include<cstdio>
using namespace std;
const int N=100005;
int fa[N*2],he[N*2],shu[N*2];
int n,m;
inline void chu()
{
	for(int i=1;i<=n;i++)
		fa[i]=i+n,fa[i+n]=i+n,he[i+n]=i,shu[i+n]=1;
}
int cha(int s){	return fa[s]==s?s:fa[s]=cha(fa[s]);}
inline void bing(int a,int b)
{
	int ba=cha(a),bb=cha(b);
	if(ba!=bb) 
	{
		fa[ba]=bb,
		he[bb]+=he[ba],
		shu[bb]+=shu[ba];
	}
}
inline void yi(int a,int b)
{
	int ba=cha(a),bb=cha(b);
	if(ba!=bb)
	{
		fa[a]=bb;
		he[ba]-=a,he[bb]+=a;
		shu[ba]--,shu[bb]++;
	}
}
inline void sum(int s)
{
	int ba=cha(s);
	printf("%d %d\n",shu[ba],he[ba]);
}
int main()
{
    freopen("a.in","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		chu();
		while(m--)
		{
			int op,p,q;
			scanf("%d%d",&op,&p);
			if(op==1)
			{
				scanf("%d",&q);
				bing(p,q);
			}
			else if(op==2)
			{
				scanf("%d",&q);
				yi(p,q);
			}
			else sum(p);
		}
	}
	return 0;
}