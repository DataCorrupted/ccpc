//FZU1483 Sicily1424 奖金 拓扑排序有环
//first topology by myself,cheer up!
//copyright by ametake
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

int n,m,x,y;
const int maxn=10001; 
int r[maxn]={0},c[maxn]={0},a[maxn][301]={0};
int ans[maxn];
int tot=0,money=0,k=0,t=0;

int main()
{
	freopen("1.txt","r",stdin); 
	while (scanf("%d%d",&n,&m)==2)
	{
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			r[x]++;
			c[y]++;
			a[y][c[y]]=x;
		}
		//先考虑黄学长的实现，再自己写队列实现 
		while (tot<n)//没节点有全部删完 tot代表已删的节点
		{
			t=0;
			for (int i=1;i<=n;i++)
			  if (!r[i])//如果i节点入度为0，那么存储这个节点并删除 
			  {
			    tot++;t++;
		        ans[t]=i;
			    r[i]=maxn;
			    money+=100; 
			  }
			if (!t) {printf("Poor Xed\n");return 0;}
			money+=k*t;//对于每一个层次补齐差价，k为每个人的差价 
			k++;
			for (int i=1;i<=t;i++)
			{
				for (int j=1;j<=c[ans[i]];j++)
				{
					r[a[ans[i]][j]]--;
				}
			} 
		}
		printf("%d\n",money);
	}
	return 0;
}
