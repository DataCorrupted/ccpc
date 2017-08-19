//codevs2296 SDOI08 ���̶� ŷ������
//copyright by ametake 
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=40000+10;
int phi[maxn]={0};
int i,n;

void getphi()//Eratosthenes while eular phiһ��ɸ��һ����ŷ������ û�б��Ϊ��������һ�����������  
{
	phi[1]=1;//exception
	for (int i = 2;i <= n;i++)
	{
		if (!phi[i])//if i is a prime number
		{
			for (int j = i;j <= n;j += i)//for every i's multiple
			{
				if (!phi[j]) phi[j] = j;//now j is composite number so not 0 
				phi[j]=phi[j] / i * (i-1);
			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	getphi();
	int ans=0;
	for (i = 2;i <= n-1;i++) ans += (phi[i] * 2); 
	ans += 3;
	printf("%d",ans);
	return 0;
}
