//codevs1036 商务旅行 LCA
//copyright by ametake
//since 19:20
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=30000+10;
int depth[maxn],fa[maxn];
int head[maxn],to[maxn*2],next[maxn*2];//twice again!!!
int n,m;
int et;
int up[maxn][20];

void add(int x,int y)
{
	et++;
	to[et]=y;
	next[et]=head[x];
	head[x]=et;
}

void dfs(int now)
{
	int t=head[now];
	while (t)
	{
		if (depth[to[t]])
		{
			t=next[t];
			continue;
		}
		depth[to[t]]=depth[now]+1;//不能写depth[now]++ 这样depth[now]也会+1 
		fa[to[t]]=now;
		dfs(to[t]);
		t=next[t];
	}
	return;
}

void doit()
{
	for (int i=1;i<=n;i++) up[i][0]=fa[i];
	for (int j=1;j<=14;j++)
	{
		for (int i=1;i<=n;i++)
		{
			up[i][j]=up[up[i][j-1]][j-1];
		}
	}
}

int lca(int x,int y)
{
	if (depth[x]<depth[y]) swap(x,y);
	int dt=depth[x]-depth[y];
    for (int i=0;i<=14;i++)
	{
		if (dt&(1<<i)) x=up[x][i];
	}
	if (x==y) return x;
	for (int i=14;i>=0;i--)
	{
		if (up[x][i]!=up[y][i])
		{
			x=up[x][i];
			y=up[y][i];
		}
	}
	return up[x][0];
}

int main()
{
	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	int x,y;
	memset(head,0,sizeof(head));
	memset(depth,0,sizeof(depth));
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	depth[1]=1;
	dfs(1);
	doit();//make st
	scanf("%d",&m);
	scanf("%d",&y);
	int ans=0;
	for (int i=1;i<m;i++)
	{
		scanf("%d",&x);
		ans=ans+depth[x]+depth[y]-(2*depth[lca(x,y)]);
		y=x;
	}
	printf("%d",ans);
	while (1);
	return 0;
} 
