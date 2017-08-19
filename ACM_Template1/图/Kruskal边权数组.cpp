//codevs2627 ���ͨ Kruskal
#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;

const int maxn=10000+10;//���鿪С������ ����ԭ���������ô����� 
const int maxdis=100000+10;
int u[maxn],v[maxn],w[maxdis],r[maxdis],p[maxn];//left right length number ufs's tree number
int n;

int cmp(const int &i,const int &j){//rules of sort 
	return w[i]<w[j];
}

int find(int x){//���鼯 Union-Find Set 
	return p[x]==x?x:p[x]=find(p[x]);
}

void kruskal(){
	int ans=0;
	for (int i=0;i<n*n;i++){//ÿ���߱�Ÿ���ֵ��������iС�ıߴ���r[i]����Ų�һ����i 
		r[i]=i;
	}
	for (int i=0;i<n;i++){//���鼯��ţ�һ��ʼÿ���㶼��ǿ��ͨ���� 
		p[i]=i;
	}
	sort(r,r+n*n,cmp);//����������� 
	for (int i=0;i<n*n;i++){//����ÿ���ߣ����������˵��Ƿ���һ�������ڣ�������ϲ� 
		int e=r[i];//ȡ����iС�ı� 
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
	init(); //û������������TUT 
	kruskal();
	return 0;
}
