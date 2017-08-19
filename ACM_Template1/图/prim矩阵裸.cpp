//最小生成树模板 未优化prim
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=200+10;
const int maxint=65534;
int w[maxn][maxn],flag[maxn];
int i,j,k,t,v,e;//v is point while e is edge

void init(){
	freopen("1.txt","r",stdin);
	memset(w,0,sizeof(w));
	memset(flag,true,sizeof(flag));
	scanf("%d%d",&v,&e);
	for (k=0;k<e;k++){
		scanf("%d%d%d",&i,&j,&t);//notice!you can't read i,j,w[i][j] together for they're read in at the same time
		w[i][j]=t;
		w[j][i]=w[i][j];
	}
	return;
}

void prim(int v0){
	int ans=0;
	int prek,nextk;
	flag[v0]=false;
	for (i=0;i<v-1;i++){
		int minn=maxint;
		for (k=1;k<=v;k++){
			if (!flag[k]){
				for (j=1;j<=v;j++){
					if ((flag[j])&&(w[k][j])&&(w[k][j]<minn)){
						minn=w[k][j];
						prek=k;
						nextk=j;
					}
				}
			}
		}
		if (minn!=maxint){
			flag[nextk]=false;
			printf("%d %d %d\n",prek,nextk,minn);
			ans+=w[prek][nextk];
		}
	}
	printf("%d",ans);
	return;
}

int main(){
	init();
	prim(1);
	return 0;
} 
