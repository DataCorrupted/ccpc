//codevs4265 大智的妹子们 二分图匹配-匈牙利
//copyright by ametake
//Hungarian cheer up!匈牙利人加油！布拉迪斯拉发加油！
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=10000+10;
struct node
{
    int t,nxt;
}e[maxn*2];
int hd[maxn],et=0;
int n,m,p;
int matching[maxn],check[maxn];

void add(int x,int y)
{
    et++;
    e[et].t=y;
    e[et].nxt=hd[x];
    hd[x]=et;
}

bool dfs(int u)
{
    for (int i=hd[u];i;i=e[i].nxt)
    {
        int v=e[i].t;
        if (!check[v])
        {
            check[v]=true;
            if (matching[v]==-1||dfs(matching[v]))
            {
                matching[v]=u;
                matching[u]=v;
                return true;
            }
        }
    }
    return false;
}

int hungarian()
{
    int ans=0;
    memset(matching,-1,sizeof(matching));
    for (int i=1;i<=n+m;i++)
    {
        if (matching[i]==-1)
        {
            memset(check,false,sizeof(check));
            if (dfs(i)) ++ans;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&p);
    int x,y;
    for (int i=1;i<=p;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y+n);
        add(y+n,x);
    }
    printf("%d\n",hungarian());
    return 0;
}
