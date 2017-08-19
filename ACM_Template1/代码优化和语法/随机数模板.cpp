//codevs3027 线段覆盖2 线性DP思想类似背包DP
//与背包的区别是没有容量上限 但要求两两不覆盖而已
//写完以后尝试一下线段覆盖1可不可以用DP
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
