//qosrt for main;
#include<iostream>
using namespace std;
int a[1000][3];
void qsort(int i,int j){
	int l,r,mid,temp;
	l=i;
	r=j;
	mid=a[(l+r)/2][1];
	while (l<r){
		while (a[l][1]<mid) l++;
		while (a[r][1]>mid) r--;
		if (l<=r){
			temp=a[l][1];
			a[l][1]=a[r][1];
			a[r][1]=temp;
			temp=a[l][2];
			a[l][2]=a[r][2];
			a[r][2]=temp;
			l++;
			r--;
		}
		if (l<j) qsort(l,j);
		if (i<r) qsort(i,r);
	}
}
int main(){
	int m,n,i;
	cin>>m>>n;
	for (i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	qsort(1,n);
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
