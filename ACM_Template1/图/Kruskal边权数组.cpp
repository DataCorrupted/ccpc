//codevs2627 村村通 Kruskal
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

const int maxn=10000+10;//数组开小死掉了 根本原因是下面用错常量了 
const int maxdis=100000+10;
int u[maxn],v[maxn],w[maxdis],r[maxdis],p[maxn];//left right length number ufs's tree number
int n;

int cmp(const int &i,const int &j){//rules of sort 
	return w[i]<w[j];
}

int find(int x){//并查集 Union-Find Set 
	return p[x]==x?x:p[x]=find(p[x]);
}

void kruskal(){
	int ans=0;
	for (int i=0;i<n*n;i++){//每条边编号赋初值，排序后第i小的边存入r[i]，编号不一定是i 
		r[i]=i;
	}
	for (int i=0;i<n;i++){//并查集编号，一开始每个点都是强连通分量 
		p[i]=i;
	}
	sort(r,r+n*n,cmp);//※条件排序※ 
	for (int i=0;i<n*n;i++){//对于每条边，查找其两端点是否在一个分量内，不在则合并 
		int e=r[i];//取出第i小的边 
		if (!w[i]) continue;
		int x=find(u[e]);
		int y=find(v[e]);
		if (x!=y){
			ans+=w[e];
			p[x]=y;
		}
	}
	printf("%d",ans);
	return;
}

void init(){
	int now=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++){
			u[now]=i;v[now]=j;
			scanf("%d",&w[now++]);
		}
	}
	return;
}

int main(){
	freopen("1.txt","r",stdin);
	init(); //没加括号死掉了TUT 
	kruskal();
	return 0;
}
