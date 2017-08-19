#include<cstdio>
const int maxn=100000001;
int a[11];

int main(){
	int n,m;
	scanf("%d",&n);
	for (int i=1;i<=10;i++) a[i]=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&m);
		a[m]++;
	}
	for (int i=1;i<=10;i++){
		for (int j=1;j<=a[i];j++){
			printf("%d\n",i);
		}
	}
	printf("\n");
	return 0;
}
