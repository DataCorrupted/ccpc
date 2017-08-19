//codevs1021 ������ ɾ�����· SPFA
//copyright by ametake
//first time to write SPFA&&edge deleted shortest road,HURRY UP! 
//������������SPFAģ�� �Ż�ģ��Ҳ������� ע�������Ŀ�����˾���ͼ 1���㳬ʱ ���ڽӱ���ܻ��Щ 
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn=1000+10;
int v,e,map[maxn][maxn],dist[maxn],pre[maxn],head=0,tail=0,res;
bool in[maxn];
queue<int> q; 


void init()
{
	scanf("%d%d",&v,&e);
	int a,b,d;
	memset(map,0x3f,sizeof(map));
	memset(pre,0,sizeof(pre));
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
	memset(dist,0x3f,sizeof(dist));
	memset(in,false,sizeof(in));
	dist[1]=0;
	q.push(1);
	in[1]=true;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		in[u]=false;//it's here!!!!!!!!!
		for (int i=1;i<=v;i++)
		{
			if (dist[i]>dist[u]+map[u][i])
			{
				if ((u!=head)||(i!=tail)) 
				{
					dist[i]=dist[u]+map[u][i];
					pre[i]=u;
					if (!in[i]) q.push(i);
					in[i]=true;
				}
			}
		}
	}
	res=dist[v];

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
	//����ÿ�������·�ϵı� ɾ�� spfa
	//���س��� �Ƚ� ѡ����Сֵ
	//ѭ�������� ������Сֵ 
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
