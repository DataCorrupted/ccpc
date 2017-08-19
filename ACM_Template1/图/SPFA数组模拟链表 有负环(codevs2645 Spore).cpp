//codevs2645 Spore SPFA有负环+数组模拟链表
//copyright by ameatke
//first time to right link graph,cheer up!
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int m,n,g1,g2,c1,c2;
int et,head[20001],ld[20001],next[20001],val[20001];
int dis[1001],cnt[1001],inq[1001],flag;
//队列中存的是待松弛的点，head存的是以这个点为起点的第一条编的编号
//next存的是同起点边序列的下一条编的编号
//p是边的编号，每一次从同起点序列的第一条边开始向后遍历，直到next[p]==0说明这是最后一条边 

void insert(int &a,int &b,int &c) 
{
	et++;//et is the number of edge
	ld[et]=b;
	val[et]=c;
	next[et]=head[a];//next edge point to the first edge who has the same start,the last next is 0
	head[a]=et;//turn the first edge to now edge,also a number
}  

void spfa()
{
	queue<int> q;
	int p;
	dis[1]=0;
	inq[1]=1;
	cnt[1]=1;
	q.push(1);
	while (!q.empty())
	{
		p=head[q.front()];//p is the number of the first edge whose start is a
		while (p)
		{
			if (dis[q.front()]+val[p]<dis[ld[p]])
			{
				dis[ld[p]]=dis[q.front()]+val[p];
				cnt[ld[p]]++;
				if (cnt[ld[p]]>n)
				{
					printf("No such path\n");flag=1;return;
				}
				if (!inq[ld[p]])
				{
					inq[ld[p]]++;
					q.push(ld[p]);
				}
			}
			p=next[p];
		}
		inq[q.front()]=0;
		q.pop();
	}
	return;
}

int main()
{
	while (scanf("%d%d",&n,&m)&&n)
	{
		flag=0;et=0;
		memset(next,0,sizeof(next));
		memset(head,0,sizeof(head));
		memset(cnt,0,sizeof(cnt));
		memset(inq,0,sizeof(inq));
		memset(dis,0x3f,sizeof(dis));
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%d%d",&g1,&g2,&c1,&c2);
			insert(g1,g2,c1);
			insert(g2,g1,c2);
		}
		spfa();
		if (!flag)
		{
			if (dis[n]==0x3f3f3f3f) printf("No such path\n");
			else printf("%d\n",dis[n]);
		}
	}
	return 0;
}
