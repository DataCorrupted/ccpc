//codevs1087 麦森数 高精+快速幂
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int maxn=100+10;
const int power=5;
const int base=100000;
long long a[maxn],ans[maxn],c[maxn];

void multi(long long *a,long long *b)
{
    memset(c,0,sizeof(c));
    int len1=a[0];
    int len2=b[0];
    c[0]=min((long long)100,a[0]+b[0]-1);
    for (int i=1;i<=len1;i++)
    {
        for (int j=1;j<=min(len2+i-1,100-i+1);j++)
        {
            c[i+j-1]+=a[i]*b[j];
            c[i+j]+=c[i+j-1]/base;
            c[i+j-1]%=base;
        }
    }
    if (c[c[0]+1]) if (c[0]<100) c[0]++;
}

void print(long long *a)
{
    int cnt=0;
    for (int i=100;i>0;i--)
    {
        cnt++;
        printf("%05lld",a[i]);
        if (cnt%10==0) printf("\n");
    }
    return;
}


int main()
{
    int p;
    scanf("%d",&p);
    printf("%d\n",int(p*log10(2)+1));
    a[0]=1;
    a[1]=2;
    ans[0]=1;
    ans[1]=1;
    while (p)
    {
        if (p&1==1)
        {
            multi(ans,a);
            memcpy(ans,c,sizeof(c));
        } 
        multi(a,a);
        memcpy(a,c,sizeof(c));
        p>>=1;
    }
    ans[1]-=1;
    print(ans);
    return 0;
} 

/*
先写一个普京快速幂= =
传进来三个数 a,b,c
设一个ans=1;
while (b)
{
    if (b & 1 == 1) ans*=a;
    a*=a;
    b>>=1;
} 
*/
