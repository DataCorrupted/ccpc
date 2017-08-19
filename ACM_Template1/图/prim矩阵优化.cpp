//最小生成树 prim矩阵优化O(nlogn)
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000+10;
const int maxint=65535;
int w[maxn][maxn],cost[maxn];
bool visit[maxn];
int i,j,v,e,k,x,y;

void init(){
	freopen("1.txt","r",stdin);
	memset(w,0,sizeof(w));
	memset(visit,true,sizeof(visit));
	scanf("%d%d",&v,&e);
	int t;
	for (k=0;k<e;k++){
		scanf("%d%d%d",&i,&j,&t);//notice!you can't read i,j,w[i][j] together for they're read in at the same time
		w[i][j]=t;
		w[j][i]=w[i][j];
	}
	return;
}

void prim(){
	int ans=0;
	visit[1]=false;
	for (i=2;i<=v;i++){
		cost[i]=maxint;
		if (w[1][i]) cost[i]=w[1][i];
	}
	int minn,minj;
	for (i=1;i<v;i++){//v-1 tiao bian
		minn=maxint;
		for (j=2;j<=v;j++){//choose the minest edge point
			if ((visit[j])&&(cost[j])&&(cost[j]<minn)){
				minn=cost[j];
				minj=j;
			}
		}
	    visit[minj]=false;
	    ans+=minn;
	    for (j=1;j<=v;j++){
	    	if ((visit[j])&&(w[minj][j])&&(w[minj][j]<cost[j])) cost[j]=w[minj][j];
		}
	}
	printf("%d",ans);
}
int main(){
	init();
	prim();
	return 0;
}
 
