//手写读入优化~高举里奥主义鲜明旗帜 
#include<cstdio>
using namespace std;

int a,b;

inline void read(int &a)
{
	int f=1;
	a=0;
	char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9')
	{
		a=a*10+ch-48;
		ch=getchar();
	}
	a*=f;
} 

int main()
{
	read(a);
	read(b);
	printf("%d\n",a+b);
	return 0;
}

