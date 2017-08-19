//qosrt for main;
#include<iostream>
using namespace std;
int a[1000][3];

int main(){
	int m,n,i,temp;
	cin>>m>>n;
	for (i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for (i=1;i<=n;i++){
		for (int j=1;j<=n-i;j++){
			if (a[j][1]>a[j+1][1]){
				temp=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=temp;
				temp=a[j][2];
				a[j][2]=a[j+1][2];
				a[j+1][2]=temp;
			}
		}
	}
	i=1;
	int ans=0;
    while (m>=a[i][2]){
   		m-=a[i][2];
   		ans+=a[i][1]*a[i][2];
   		i++;
   	}
    ans+=a[i][1]*m;
	cout<<ans;
	return 0;
}
