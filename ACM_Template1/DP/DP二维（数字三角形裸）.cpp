//codevs1220 ���������� DP
//copyright by ametake
//annotation:����������������Σ������DP ȡģ�ͷ���һ���Ǹ���ûŪ���� ����������ר��ʱ���� 
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

int n,a[100+10][100+10];

int main()
{
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=i;j++)
	  {
	  	scanf("%d",&a[i][j]);
	  }
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=i;j++)
	  {
	  	a[i][j]+=max(a[i-1][j-1],a[i-1][j]);
	  }
	int ans=0x80000000;  
	for (int i=1;i<=n;i++) ans=max(ans,a[n][i]);
	printf("%d\n",ans);
	return 0;
} 
