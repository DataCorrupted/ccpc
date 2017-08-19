//codevs2370 小机房的树 LCA最近公共祖先 目前现状：A一半W一半 大数据W 静态查代码 
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=50000+10;
int p[maxn][20],cost[maxn][20];//cost表示从节点i向上蹦2^j至某一节点t的路程中花费的精力和
int father[maxn];
int depth[maxn];
int power[20];
int et=0,t[maxn],val[maxn],head[maxn],next[maxn];//边的编号，去路，权值，以同一节点开始的第一条边的编号，这条边连接的下一条编的编号 
int n;

void add(int from,int to,int v)
{
    et++;
    t[et]=to;
    val[et]=v;
    next[et]=head[from];
    head[from]=et;
}

void makepower()
{
    power[0]=1;
    power[1]=2;
    int cnt=1;
    for (int i=2;i<20;i++)
    {
        power[cnt+1]=power[cnt]*2;
        cnt++;
    }
}

void dfs(int now)
{
    int i=head[now];
    while (i!=0)
    {
        if (depth[t[i]])
        {
        	i=next[i];
        	continue;
		}
        depth[t[i]]=depth[now]+1;
        father[t[i]]=now;//notice
        cost[t[i]][0]=val[i];
        dfs(t[i]);
    }
}

void doit()
{
    for (int i=1;i<=n;i++)
    {
        p[i][0]=father[i];
    } 
    for (int j=1;j<20;j++)
    {
        for (int i=1;i<=n;i++)
        {
            p[i][j]=p[p[i][j-1]][j-1];
            cost[i][j]=cost[p[i][j-1]][j-1]+cost[i][j-1];
        }
    }
}

int lca(int u,int v)
{
    int ans=0;
    if (depth[u]<depth[v]) swap(u,v);//u is big
    int dt=depth[u]-depth[v];
    for (int j=19;j>=0;j--)
    {
        if (dt==0) break;
        if (power[j]<=dt)//<= not <
        {
            dt-=power[j];
            ans+=cost[u][j];
            u=p[u][j];
        }
    }
    for (int j=19;j>=0;j--)
    {
        if (p[u][j]!=p[v][j])
        {
            ans+=cost[u][j];
            ans+=cost[v][j];
            v=p[v][j];
            u=p[u][j];
        }
    }
    if (u!=v)
    {
    	ans=ans+cost[u][0];
        ans=ans+cost[v][0];
    }
    return ans;
}


int main()
{
    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    int u,v,c;
    memset(head,0,sizeof(head));
    for (int i=1;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&c);
        add(u+1,v+1,c);
        add(v+1,u+1,c);
    }
    memset(father,0,sizeof(father));
    memset(depth,0,sizeof(depth));
    makepower();
    father[1]=1;
    depth[1]=1;
    dfs(1);
    doit();
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u+1,v+1));
    }
    while(1);
    return 0;
}

/*
*首先读入边 邻接表存储
*然后DFS一次，求层次和father
*然后预处理出来p和cost
*对每个数据进行计算 
*/
