//kuaisumifeidigui;
#include<iostream>
#include<cstdlib>
using namespace std;
void mi(long long a,long long b,long long c);
int main(){
	long long a,b,c; 
	cin>>a>>b>>c;
	mi(a,b,c);
	return 0;
}
void mi(long long a,long long b,long long c){
	long long ans=1;long long x,y,z;x=a;y=b;z=c;
	while (b>0){
		if (b & 1==1) ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	cout<<x<<'^'<<y<<" mod "<<z<<'='<<ans;
}
