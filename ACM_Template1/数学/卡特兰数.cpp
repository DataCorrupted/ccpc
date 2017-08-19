//Õ» ¿¨ÌØÀ¼Êý
#include<iostream>
using namespace std;

long long n,f[20]={0};

/*NO.1 f[n+1]=f[i]*f[n-i]from 0 to n plus  f[0]=1 
int main(){
	cin>>n;
	f[0]=1;f[1]=1;
	for (int i=2;i<=n;i++){
		for (int j=0;j<i;j++){
			f[i]+=f[j]*f[i-j-1];
		}
	}
	cout<<f[n];
	return 0;
} 
*/

/*NO.2 f[n+1]=((4n+2)*f[n])/(i+2) f[0]=1
int main(){
	cin>>n;
	f[0]=1;
	for (int i=0;i<n;i++) f[i+1]=(4*i+2)*f[i]/(i+2);
	cout<<f[n];
	return 0;
}
*/

/*NO.3 WRONG!right when n<=9 f[n]=(n+2 multi to 2n)/(n!)   even use son*(n+i)/i is also wrong,refering to real number(double)
int main(){
	cin>>n;
	int son=1;
	for (int i=n+2;i<=2*n;i++) son*=i;
	for (int i=n;i>=2;i--) son/=i;
	cout<<son;
}
*/


