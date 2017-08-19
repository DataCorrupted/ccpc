//codevs4214 品尝美食
//出自TY君20151011模拟赛
//copyright by ametake 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=100000+10;
int n,a[maxn];
int f[maxn];
int p;

int find(int x)//目标：找出当前序列中比x大的第一个数的位置 
{
    return lower_bound(f+1,f+p+1,x)-f;//lower_bound返回不小于他的最小值，upper_bound返回大于它的最小值，二分 
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]-=i;
    }
    p=1;//pointer
    f[1]=a[1];
    for (int i=2;i<=n;i++)
    {
        if (a[i]>=f[p])
        {
            f[++p]=a[i];
        }
        else 
        {
            int pos=find(a[i]);
            f[pos]=a[i];
        }
    }
    printf("%d",n-p);
    return 0;
}
