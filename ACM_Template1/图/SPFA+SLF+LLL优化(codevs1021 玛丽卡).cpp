//codevs1021 玛丽卡 SPFA+SLF+LLL优化 
//copyright by ametake
//first time to write SPFA&&edge deleted shortest road,HURRY UP! 
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

/*struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.priority < n2.priority;
    }
    int priority;
    int value;
};*/
struct w
{
	int dist,num;
	bool operator < (w n2)const
	{
		return dist<n2.dist;
	}             
};
const int maxn=1000+10;
int v,e,map[maxn][maxn],pre[maxn],head=0,tail=0,res;
bool in[maxn];
w node[maxn];
priority_queue<w> q; 


void init() 
{
	scanf("%d%d",&v,&e);
	int a,b,d;
	memset(map,0x3f,sizeof(map));
	memset(pre,0,sizeof(pre));
	for (int i=0;i<maxn;i++) node[i].num=i;
	for (int i=0;i<e;i++)
	{
		scanf("%d%d%d",&a,&b,&d);
		map[a][b]=d;
		map[b][a]=d;  
	}          
	return;
}                              

void spfa()
{
	for (int i=0;i<maxn;i++) node[i].dist=0x3f3f3f3f;
	memset(in,false,sizeof(in));
	node[1].dist=0; 
	q.push(node[1]);
	in[1]=true;
	while (!q.empty())
	{
		int u=q.top().num;
		q.pop();
		in[u]=false;//it's here!!!!!!!!!
		for (int i=1;i<=v;i++)
		{
			if (node[i].dist>node[u].dist+map[u][i])
			{
				if ((u!=head)||(i!=tail)) 
				{
					node[i].dist=node[u].dist+map[u][i];
					pre[i]=u;
					if (!in[i]) q.push(node[i]);
					in[i]=true;
				}
			}
		}
	}
	res=node[v].dist;

	return;
}

void work()
{
	spfa();
	int i=v;
	int ans=0;

	int b[maxn];
	memcpy(b,pre,sizeof(b));
	do
	{
		head=b[i];
		tail=i;                                                                                                                   
		//int temp=map[head][tail];
		//map[head][tail]=0x3f3f3f3f;
		spfa();
		if (res>ans) ans=res;
		//map[head][tail]=temp;
		i=head;
	}while (i!=1);
	//对于每条在最短路上的边 删边 spfa
	//返回长度 比较 选择最小值
	//循环结束后 返回最小值 
	printf("%d\n",ans);
	return;
}

int main()
{
	freopen("1.txt","r",stdin);
	init();
	work();
	return 0;
}
