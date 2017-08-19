//codevs1611 抢掠计划 强连通Tarjan缩点
//copyright by ametake
//Cheer up !!!
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int maxn=500000+10;
int n,m;
int S,P;
int head[maxn],to[maxn<<2],next[maxn<<2],et=0;
int money[maxn];
bool inq[maxn],ins[maxn];
int dfn[maxn],low[maxn],sta[maxn],stp=0,tot=0;//stp is the point of stack ans tot is the number of the strongly connected components
int inwhich[maxn],scc[maxn];//in which scc and the scc contains how much money
int dis[maxn],dep;
vector<int> g[maxn];
queue<int> q;

inline void add(int &x,int &y)
{
    et++;
    to[et]=y;
    next[et]=head[x];
    head[x]=et;
}

inline int read()
{
    int a=0,b=1;
    char ch=getchar();
    while (ch<'0'||ch>'9')
    {
        if (ch=='-') b=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        a=a*10+ch-'0';
        ch=getchar();
    }
    a*=b;
    return a;
} 

void init()
{
    n=read();
    m=read();
    int x,y;
    for (int i=0;i<m;i++)
    {
        x=read();
        y=read();
        add(x,y);
    }
    for (int i=1;i<=n;i++)
    {
        money[i]=read();
    }
    S=read();
    P=read();
    return;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++dep;
    sta[++stp]=x;
    ins[x]=true;
    int t;
    for (t=head[x];t!=0;t=next[t])
    {
        if (dfn[to[t]]==0)
        {
            tarjan(to[t]);
            low[x]=min(low[to[t]],low[x]);
        }
        else if (ins[to[t]])
        {
            low[x]=min(low[x],dfn[to[t]]);
        }
    }
    if (dfn[x]==low[x])
    {
        tot++;
        int j;
        do
        {
            j=sta[stp--];
            ins[j]=false;
            inwhich[j]=tot;
            scc[tot]+=money[j];
        }while (j!=x);
    }
}

void spfa(int s)//443412
{
    inq[s]=true;
    q.push(s);
    dis[s]=scc[s];
    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        inq[now]=false;
        for (int i=0;i<g[now].size();i++)
        {
            if (dis[now]+scc[g[now][i]]>dis[g[now][i]])
            {
                dis[g[now][i]]=dis[now]+scc[g[now][i]];
                if (!inq[g[now][i]])
                {
                    q.push(g[now][i]);
                    inq[g[now][i]]=true;
                }
            }
        }
    }
    int now,ans=0;
    for (int i=1;i<=P;i++)
    {
        now=read();
        //printf("%d %d\n",now,dis[inwhich[now]]);
        if (dis[inwhich[now]]>ans) ans=dis[inwhich[now]];
    }
    printf("%d\n",ans);
}

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    init();
    for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
    //for (int i=1;i<=n;i++) printf("%d\n",inwhich[i]);
    /*
    for (int i=1;i<=tot;i++)
    {
        printf("%d.%d\n",i,scc[i]);
    }
    */
    for (int i=1;i<=n;i++)
    {
        for (int j=head[i];j!=0;j=next[j])
        {
            if (inwhich[to[j]]!=inwhich[i])
            {
                g[inwhich[i]].push_back(inwhich[to[j]]);//now there's no single point,every point is in a scc
            }
        }
    }
    spfa(inwhich[S]);
    return 0;
}
