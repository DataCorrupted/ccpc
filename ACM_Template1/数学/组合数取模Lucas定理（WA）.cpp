//HDU3037 Saving Beans Lucas定理组合数取模 
//copyright by ametake

#include<iostream>
using namespace std;

typedef long long ll;

ll t,n,m,p;

ll multi(ll a,ll b)
{
	ll ans=1;
	while (b>0)
	{
		if (b & 1 == 1) ans=((ll)ans*(ll)a)%p;
		a =( (ll)a * (ll)a ) % p;
		b =(ll)(b << 1); 
	}
	return ans;
}

ll c(ll n,ll m)
{
	ll a=1,b=1;
	if (m>n) return 0;
    while (m)
    {
    	a=(a*n)%p;
    	b=(b*m)%p;
    	m--;
    	n--;
    	
	}
	return ((ll)a*(ll)multi(b,p-2))%p;
}

ll lucas(ll n,ll m,ll p)
{
	if ( !m ) return 1;
	else return ( (ll)lucas(n/p,m/p,p)*(ll)c(n%p,m%p)&p);
}

int main()
{
	cin>>t;
	for (ll i=1;i<=t;i++)
	{
		cin>>n>>m>>p;
		cout<<lucas(n+m,m,p)<<endl;
	}
	return 0;
}
 
