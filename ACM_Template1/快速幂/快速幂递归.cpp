//kuaisumidigui;
#include<iostream>
using namespace std;
long long mi(int a,int b,int c);

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout<<mi(a,b,c);
	return 0;
}
long long mi(int a,int b,int c){
	if (b==0) return 1;
	long long x=mi(a,b/2,c);
	long long ans=(x*x)%c;
	if (b%2==1) ans=(ans*a)%c;
	return ans;
}
