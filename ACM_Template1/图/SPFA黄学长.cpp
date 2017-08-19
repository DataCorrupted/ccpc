//codevs1021 玛丽卡 SPFA+数组模拟邻接表 黄学长正解 hzwer 
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct data{
	int from,to,next,v;
}e[1000001];
int n,m,ans;
int ne;
int head[1001];
bool inq[1001],del[1000001];
int q[1000001],dis[1001],father[1001];
void insert(int u,int v,int w)
{
	ne++;
	e[ne].from=u;
	e[ne].to=v;
	e[ne].v=w;
	e[ne].next=head[u];
	head[u]=ne;
}
void spfa(int k)
{
	memset(dis,127,sizeof(dis));
	memset(inq,0,sizeof(inq));
	int t=0,w=1,now;
	q[t]=1;inq[1]=1;dis[1]=0;
	while(t<w)
	{
		int p=head[q[t]];
		now=q[t];t++;
		while(p)
		{
           if(!del[p]&&dis[now]+e[p].v<dis[e[p].to])
           {
           	  dis[e[p].to]=dis[now]+e[p].v;
           	  if(k==1)father[e[p].to]=p;
           	  if(!inq[e[p].to])
           	  {
           	  	 inq[e[p].to]=1;
           	  	 q[w++]=e[p].to;
           	  }
           }
           p=e[p].next;
		}
		inq[now]=0;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);insert(y,x,z);
	}
	spfa(1);
	ans=dis[n];
	for(int i=n;i!=1;i=e[father[i]].from)
	{
		del[father[i]]=1;spfa(0);del[father[i]]=0;
		ans=max(dis[n],ans);
	}
	printf("%d",ans);
	return 0;
}
