//拓扑排序 家谱树 队列版 
//拓扑一次 输出路径 不判环 
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int n; 
int r[101]={0},c[101]={0},a[101][101]={0};//a数组表示第i个数的第某个出度是谁 
queue<int> ans;

int main()
{
	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	int j;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&j);
		while (j)
		{
			r[j]++;
			c[i]++;
			a[i][c[i]]=j;
			scanf("%d",&j);
		}
    }
	int t=0;
	for (int i=1;i<=n;i++)
	{
		if (!r[i]) ans.push(i);
	}
	while (!ans.empty())
	{
		j=ans.front();
		printf("%d ",j);
		ans.pop();
		for (int i=1;i<=c[j];i++)
		{
			r[a[j][i]]--;
			if (!r[a[j][i]]) ans.push(a[j][i]);
		}
	}
	return 0;
} 
