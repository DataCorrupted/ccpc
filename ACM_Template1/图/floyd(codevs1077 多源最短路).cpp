//codevs1077 多源最短路
//copyright by ametake
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=0x3f3f3f3f;
int a[101][101];

int main()
{
	freopen("1.txt","r",stdin); 
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int x,y;
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",a[x-1][y-1]);
	}
	return 0;
} 
