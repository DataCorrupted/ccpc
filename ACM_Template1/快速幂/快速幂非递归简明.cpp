#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

long long  mi(long long a,long long b,long long c)
{
    for(long long t = a, B = b-1; B; B >>= 1, t = (t%c) * (t%c) % c)
	if(B&1) a = (a%c) * (t%c) % c;
    return a;
}

int main(){
	freopen("1.txt","r",stdin);
	long long a,b,c; 
	cin>>a>>b>>c;
	cout<<mi(a,b,c);
	return 0;
}


