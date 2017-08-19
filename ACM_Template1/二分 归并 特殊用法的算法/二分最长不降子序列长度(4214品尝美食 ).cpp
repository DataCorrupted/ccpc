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
    int l=1,r=p;
    while (l<r)
    {
        int mid=(l+r)/2;
        if (f[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
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

/*
二分：

****a[x]>=k的最小x****

mid=(L+R) div 2;
if a[mid]>=k 
then r:=mid  
else l:=mid+1; 


****a[x]<=k的最大x****
mid:=(l+r+1) div 2;
if a[mid]<=k 
then l:=mid 
else r:=mid-1;

********************** 
*/
