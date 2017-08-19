//codevs3342 绿色通道 二分+单调队列优化DP
//copyright by ametake
//thanks to 量子纠缠 from NUST and wu_yihao from CSDN 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=50000+10;
int n,t;
int a[maxn],f[maxn],q[maxn];


bool can(int x)
{
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    int l=0,r=0;
    q[r++]=0;
    for (int i=1;i<=n;i++)
    {
        while (l<=r&&q[l]<i-x-1) l++;//删除队列头部所有位置小于查询起始位置的数字
        f[i]=a[i]+f[q[l]];//查询修改后的头元素（最小元素） 
        while (l<=r&&f[q[r]]>=f[i]) r--;//删除队列尾部所有耗时比当前元素大的元素
        q[++r]=i; 
        /*
        //朴素的写法是这样的： 
        for (int j=max(i-x-1,0);j<i;j++)
        {
            f[i]=min(f[i],f[j]+a[i]);
        }
        */
    }
    int ans=0x3f3f3f3f;
    for (int i=n-x-1;i<=n;i++) ans=min(ans,f[i]);
    return ans<=t; 
}

int main()
{
    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&t);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int l=0,r=n;
    int mid;
    while (l<r)
    {
        mid=(l+r)>>1;
        if (can(mid))
        {
            r=mid;
        }
        else l=mid+1;
    }
    printf("%d",l);
    while (1);
    return 0;
}
