//codevs3027 �߶θ���2 ����DP˼�����Ʊ���DP
//�뱳����������û���������� ��Ҫ�����������Ƕ���
//д���Ժ���һ���߶θ���1�ɲ�������DP
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;



int main()
{	
	freopen("2.txt","w",stdout);
	srand(time(NULL));
	int a = rand()%100+1;
	printf("%d\n",a);
	int b;
	for (int i=1;i<=3*a;i++)
	{
		b = rand()%100+1;
		printf("%d\n",b);
	}
	return 0;
}
