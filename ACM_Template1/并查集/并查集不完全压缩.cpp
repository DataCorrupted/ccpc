//codevs1073 家族/亲戚 并查集
#include<cstdio>
using namespace std;

const int maxn=100000+10;
int p[maxn];
int n,m,q;

int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}

/*void uni(int a,int b){
	if (p[a]!=a) uni(p[a],b);
	p[a]=b;
	return;
}*/

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){
		p[i]=i;
	}
	int x,y;
	for (int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		int xx=find(x);
		int yy=find(y);
		if (xx!=yy) p[xx]=yy;
	}
	for (int i=0;i<q;i++){
		scanf("%d%d",&x,&y);
		int xx=find(x);
		int yy=find(y);
		if (xx!=yy) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
