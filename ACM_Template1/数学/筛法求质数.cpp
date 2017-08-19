//埃拉托色尼筛法求质数
//copyright by ametake
#include<cstdio>
#include<cstring>

const int maxn=10000000;
bool a[maxn],n;

int main()
{
    freopen("prim.txt","w",stdout);
    memset(a,true,sizeof(a)); 
    for (int i=2;i<=maxn;i++)
    {
        if (a[i])
        {
            for (int j=2;j<=maxn/i;j++) a[i*j]=false;
        }
    }
    for (int i=2;i<=maxn;i++) if (a[i]) printf("%d\n",i);
    return 0;
} 
