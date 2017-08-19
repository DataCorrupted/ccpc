#include<iostream>//输入n*n矩阵 求从k到n的最短路 dijkstra 
#include<cstring>
using namespace std;

const int maxn=0xfffffff;
int cost[1010][1010],a[1010],mark[1010];
int n,k; 

void init(){
	cin>>n>>k;//n is the number of points and k is the start
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin>>cost[i][j];
		}
	}
	return;
}

void dij(){
	memset(mark,false,sizeof(mark));
	for (int i=1;i<=n;i++)a[i]=maxn;
	a[k]=0;
	for (int i =1;i<n;i++){
		int min=maxn,minj;
		for (int j=1;j<=n;j++){
			if ((!mark[j])&&(a[j]<min)){
				min=a[j];
				minj=j;
			}
			mark[minj]=true;
			for (int j=1;j<=n;j++){
				if ((!mark[j])&&(cost[minj][j]>0)&&((a[minj]+cost[minj][j])<a[j])) a[j]=a[minj]+cost[minj][j];
			}
		}	
	}
	return;
}

void outit(){
	printf("%d\n",a[n]);
	return;
}
int main(){
	init();
	dij();
	outit();
	return 0;
}
