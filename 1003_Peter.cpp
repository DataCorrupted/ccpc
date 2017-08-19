#include <iostream>  
#include <stdio.h>  
#include <string.h>  
#include <vector>  
using namespace std;  
  
const int M=55;  
vector<int> e[M];  
int isu[M];  
  
int f;  
  
void dfs(int nv,int now,int n,int k) {  
	if(f)  
		return;  
	if(isu[nv])  
	{  
		if(now-isu[nv]==k)  
			f=1;  
		return;  
	}  
	isu[nv]=now;  
	for(int i=0;i<e[nv].size();i++)  
	{  
		dfs(e[nv][i],now+1,n,k);  
	}  
}  
  
int main() {  
	int t;  
	int temp;
	int n,m;  
	int v1,v2;  
	int f1, f2;
	cout << "HELLP";
	int map[3010][3010];
	scanf("%d",&t);  
	cout << "HELLO";
	while(t--) {  
		scanf("%d",&n);  
		for (int i=1; i<n; i++){
			for (int j=1; j<n-1; j++){
				scanf("%d", &map[i,j]);
			}
		}
		f=0;  
		for(int i=0;i<n;i++) {
			e[i].clear();  
		}
		for(int i=1;i<n;i++) {  
			for (int j=1; j<n-1; j++){
				if (map[i][j] == 1){  
					e[i].push_back(i+j);  
					e[i+j].push_back(i);   
				}
			}
		}  
		for(int i=0;i<n;i++)  
		{  
			memset(isu,0,sizeof(isu)); 
			dfs(i,1,n,3);  
		}      
		f1 = f; f = 0;

		for(int i=0;i<n;i++) {
			e[i].clear();  
		}
		for(int i=1;i<n;i++) {  
			for (int j=1; j<n-1; j++){
				if (map[i][j] == 0) {
					e[i].push_back(i+j);  
					e[i+j].push_back(i);  
				}
			}
		}  
		for(int i=0;i<n;i++)  
		{  
			memset(isu,0,sizeof(isu)); 
			dfs(i,1,n,3);  
		}      
		f2 = f;
		printf("%s\n",(f1 | f2)?"YES":"NO");  
	}  
	return 0;  
}  