//codevs2038 香甜的黄油 重写 邻接表+dij堆优化
//邻接表 优先队列 挑战 加油！
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int oo ;
struct data
{
	int v,w,next;
}e[3001];//edge 终点，边权，下一条同源边 

struct w
{
	int dist,num;
	bool operator < (w n2)const
	{
		return dist>n2.dist;
	}             
}node[801];//每个node是一个点，有编号和dist 

int ne,n,p,c,a,b,d;
int head[801],cow[801];//head:edge from here;cow:the position of each cow;
bool vis[801];
int tot,ans;

void insert(int &x,int &y,int &w)
{
	ne++;
	e[ne].v=y;
	e[ne].w=w;
	e[ne].next=head[x];
	head[x]=ne;
} 

void init()
{
	scanf("%d%d%d",&n,&p,&c);
	memset(head,0,sizeof(head));
	for (int i=1;i<=n;i++) scanf("%d",&cow[i]);//from 1!
	for (int i=1;i<=c;i++)
	{
		scanf("%d%d%d",&a,&b,&d);
		insert(a,b,d);
		insert(b,a,d);
	}
}

void dij(int &k)
{
	priority_queue<w> q;
	node[k].dist=0;
	q.push(node[k]);
	int disj,minj;//dis of j and number of j
	while (!q.empty()) 
	{
		minj=q.top().num;
		disj=q.top().dist;
		vis[minj]=true;
		q.pop();
	    int pi=head[minj];
	    while (pi)
	    {
	    	if (!(vis[e[pi].v]) && (disj+e[pi].w < node[e[pi].v].dist || disj == oo))
	    	    {node[e[pi].v].dist=disj+e[pi].w;q.push(node[e[pi].v]);}
	    	pi=e[pi].next;
		}
	}
	//首先循环一边找出dist最小的点
	//然后循环一边对于每个点以dist为中间点更小就更新dist 
	//从当前dist连着的边里找 
	tot=0;
	for (int i=1;i<=n;i++) tot+=node[cow[i]].dist;//结果反馈：与K直接连着的边正常，不直接相连的正无穷未更新 
	return;
}

int main()
{
	freopen("1.txt","r",stdin);
	int inf = 0x3f3f3f3f;
	oo = inf;
	init();
	ans=0x3f3f3f3f;
	for (int i=1;i<=p;i++) node[i].num=i;
	for (int i=1;i<=p;i++)
	{
		memset(vis,false,sizeof(vis));
		for (int j=1;j<=p;j++) 
		{
		    node[j].dist=0x3f3f3f;
		}
	    dij(i);if (tot<ans) ans=tot;
	}
	printf("%d\n",ans);
	return 0;
}
