//codevs1557 热浪 单元最短路 SPFA
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=2500+10;//point
const int maxm=7000;//edge remember to multi 2

struct node
{
	int to,v,next;
}e[maxm*2];

int t,c,ts,te;
int head[maxn];
bool inq[maxn];
int dis[maxn];
int et=0;
int ans=0;

void add(int x,int y,int z)
{
	et++;
	e[et].to=y;
	e[et].v=z;
	e[et].next=head[x];
	head[x]=et;
}

void spfa(int ss,int ee)
{
	queue<int> q;
	dis[ss]=0;
	inq[ss]=1;
	q.push(ss);
	while (!q.empty())
	{
        int p=q.front();
        q.pop();
        inq[p]=0;
        int pi=head[p];
        while (pi)
        {
            if (dis[p]+e[pi].v<dis[e[pi].to])
            {
                dis[e[pi].to]=dis[p]+e[pi].v;
                if (!inq[e[pi].to])
                {
                     inq[e[pi].to]=1;
                     q.push(e[pi].to);
                }
            }
            pi=e[pi].next;
        }
    }
    ans=dis[ee];
    return;
}

int main()
{
	scanf("%d%d%d%d",&t,&c,&ts,&te);
	memset(dis,0x3f,sizeof(dis));
	int x,y,z;
	for (int i=1;i<=c;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	spfa(ts,te);
	printf("%d\n",ans);
	return 0;
}
