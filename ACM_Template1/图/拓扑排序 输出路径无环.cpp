//һ��ͨ ����������ϰ ������
//����һ�� ���·�� ���л� 
//copyright by ametake
#include<cstdio>
#include<cstring>
using namespace std;

int n,m=0;//m�ǵ�ǰ�Ѿ�����ĵ�ĸ��� 
int r[101]={0},c[101]={0},a[101][101]={0};//a�����ʾ��i�����ĵ�ĳ��������˭ 
int ans[101]={0};

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
		if (!r[i]) ans[++t]=i;
	}
	while (m!=n)
	{
		j=ans[t];
		printf("%d ",j);
		t--;
		m++;
		for (int i=1;i<=c[j];i++)
		{
			r[a[j][i]]--;
			if (!r[a[j][i]]) {t++;ans[t]=a[j][i];}
		}
	}
	return 0;
} 
