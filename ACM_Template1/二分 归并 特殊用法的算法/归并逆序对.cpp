//codevs1688 求逆序对 归并
//copyright by ametake
//模板要写好
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

const ll maxn=100000+10;
ll a[maxn],b[maxn];
ll n,total;

void msort(ll l,ll r)
{
	ll mid=l + r >> 1;
	if (l<r)
	{
		msort(l,mid);
		msort(mid+1,r);
	}
	ll i=l,k=l,j=mid+1;
	while (i<=mid&&j<=r)
	{
		if (a[i]<=a[j]) b[k++]=a[i++];
		else
		{
			total+=mid-i+1;
			b[k++]=a[j++];
		}
	}
	while (i<=mid) b[k++]=a[i++];
	while (j<=r) b[k++]=a[j++];
	for (ll i=l;i<=r;i++) a[i]=b[i];
}

int main()
{
	scanf("%d",&n);
	for (ll i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
    }
    msort(1,n);
    printf("%lld\n",total);
} 
