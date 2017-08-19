//codevs1079 »Ø¼Ò Usaco dij
//copyright by ametake
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=101;
const int maxdis=100000;
const int last=52;
int n;
int dis[maxn],cost[maxn][maxn];
bool vis[maxn];

void init(){
	scanf("%d",&n);
	memset(vis,true,sizeof(vis));
	memset(cost,-1,sizeof(cost));
	for (int i=1;i<=51;i++) dis[i]=maxdis;
	int d;
	char a,b;
	for (int i=0;i<n;i++){
		scanf("\n%c %c %d",&a,&b,&d);//notice the readin of char 
		if (a>='a'&&a<='z') a=a-'a'+1;
		else a=a-'A'+27;
		if (b>='a'&&b<='z') b=b-'a'+1;
		else b=b-'A'+27;
		if (a!=b){
			if ((cost[a][b]==-1)||(d<cost[a][b])){
				cost[a][b]=d;
				cost[b][a]=d;
			}
		}
	}
	return; 
}

void dij(){
	dis[52]=0;
	for (int i=1;i<=last-1;i++){
		int min=maxdis,minj;
		for (int j=last;j>=1;j--) if (vis[j]&&dis[j]<min){
			minj=j;
			min=dis[j];
		}
		vis[minj]=false;
		for (int j=1;j<=last;j++){
			if ((vis[j])&&(cost[minj][j])>-1){
				int temp=cost[minj][j]+dis[minj];
				if (temp<dis[j]) dis[j]=temp;
			}
		}
	}
	return;
}

void print(){
	int min=maxdis,minj;
	for (int i=27;i<=last-1;i++){
		if (dis[i]<min){
			min=dis[i];
			minj=i;
		}
	}
	printf("%c %d",minj-27+'A',min);
	return;
}

int main(){
	freopen("1.txt","r",stdin);
	init();
	dij();
	print();
	return 0;
}
 
