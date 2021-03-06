#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <vector>  

using namespace std;  

const int M = 3005;  
vector <int> e[M];  
int isu[M];  
int f;  

void dfs(int nv,int now,int n,int k) {
    int i;
    if (f) { return; }
    if (isu[nv]) {  
        if (now - isu[nv] == k) { f = 1; }
        return;  
    }  
    isu[nv] = now;  
    for (i = 0; i < e[nv].size(); i++) {  
        dfs(e[nv][i], now + 1, n, k);  
    }  
}  
  
int main() {  
    int t;  
    int n,m,k,i,j,temp;
    scanf("%d", &t);  
    while (t--) {  
        scanf("%d", &n);  
        f = 0;  
        for (i = 0; i < n; i++)  
            e[i].clear();  
        for (i = 1; i <= n - 1; i++) { 
            for (j = 1; j <= n - i; j++) {
                scanf("%d",&temp);  
                if (temp == 1) {
                    e[i].push_back(i + j);  
                    e[i + j].push_back(i);
                }
            }
        }  
        for(i = 1;i <= n;i++) {  
            memset(isu,0,sizeof(isu));
            dfs(i, 1, n, 3);  
        }      
        if (f) printf("Bad Team!\n"); else printf("Great Team!\n");
    }  
    return 0;  
}  