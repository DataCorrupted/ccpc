//codevs2296 SDOI08 仪仗队 欧拉函数
//copyright by ametake 
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=40000+10;
int phi[maxn]={0};
int i,n;

void getphi()//Eratosthenes while eular phi一边筛法一边求欧拉函数 没有标记为合数的下一个书就是质数  
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
