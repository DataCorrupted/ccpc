#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int n,m,fa[1000001][15],w[1000001],point[1000001],next[1000001],u,v,cnt,deep[1000001],vis[1000001];  
int ma[1000001][15],mi[1000001][15],zma[1000001][15],fma[1000001][15];  
struct use{  
    int st,en;  
}b[1000001];  
void add(int x,int y)  
{  
    ++cnt;next[cnt]=point[x];point[x]=cnt;  
    b[cnt].st=x;b[cnt].en=y;  
}  
void dfs(int x)  
{  
    vis[x]=1;  
    for(int i=1;i<=14;i++)  
    {  
        if(deep[x]<(1<<i))break;  //请注意这里的处理 
        fa[x][i]=fa[fa[x][i-1]][i-1];  
        ma[x][i]=max(ma[fa[x][i-1]][i-1],ma[x][i-1]);  
        mi[x][i]=min(mi[fa[x][i-1]][i-1],mi[x][i-1]);  
        zma[x][i]=max(max(zma[fa[x][i-1]][i-1],zma[x][i-1]),ma[fa[x][i-1]][i-1]-mi[x][i-1]);  
        fma[x][i]=max(max(fma[fa[x][i-1]][i-1],fma[x][i-1]),ma[x][i-1]-mi[fa[x][i-1]][i-1]);  
    }  
    for(int i=point[x];i;i=next[i])  
    {  
        if(vis[b[i].en])continue;  
        deep[b[i].en]=deep[x]+1;  
        fa[b[i].en][0]=x;  
        ma[b[i].en][0]=max(w[b[i].en],w[x]);  
        mi[b[i].en][0]=min(w[b[i].en],w[x]);  
        zma[b[i].en][0]=w[x]-w[b[i].en];  
        fma[b[i].en][0]=w[b[i].en]-w[x];  
        dfs(b[i].en);  
    }  
}  
int lca(int x,int y)  
{  
    int t;  
    if (deep[x]<deep[y]) swap(x,y);  
    t=deep[x]-deep[y];  
    for (int i=0;i<=14;i++)  
        if (t&(1<<i)) x=fa[x][i];  
    for (int i=14;i>=0;i--)  
      if (fa[x][i]!=fa[y][i]){x=fa[x][i];y=fa[y][i];}  
    if (x==y)   
         return x;  
    else   
      return fa[x][0];  
}  
int main()  
{  
freopen("1.txt","r",stdin);
freopen("2.txt","w",stdout);
    cin>>n;  
    for (int i=1;i<=n;i++) scanf("%d",&w[i]);  
    for (int i=1;i<=n-1;i++)  
      {  
         scanf("%d%d",&u,&v);  
         add(u,v);add(v,u);  
      }  
    dfs(1);  
    cin>>m;  
    for (int i=1;i<=m;i++)  
      {  
         int maxx(-1000000),minn(1000000),t,x,y,ans(-100000);  
         ans=0;  
         scanf("%d%d",&x,&y);  
         int z;  
         z=lca(x,y);  
         t=deep[x]-deep[z];  
         if (t>0)  
         {  
          for (int j=0;j<=14;j++)  
           {  
              if (t&(1<<j))//如果t的展开中有2^j 
                {  
                   ans=max(zma[x][j],ans);  
                   ans=max(ans,ma[x][j]-minn);  
                   minn=min(minn,mi[x][j]);  
                   x=fa[x][j];  
                }  
           }  
        }  
          t=deep[y]-deep[z];  
      if (t>0)  
       {  
        for (int j=0;j<=14;j++)  
           {  
              if (t&(1<<j))  
                {  
                   ans=max(fma[y][j],ans);  
                   ans=max(ans,maxx-mi[y][j]);  
                   maxx=max(maxx,ma[y][j]);  
                   y=fa[y][j];  
                }  
           }  
       }  
         ans=max(maxx-minn,ans);  
         printf("%d\n",ans);  
      }   
}  
