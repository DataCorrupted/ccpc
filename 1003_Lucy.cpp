//codevs1611 ÇÀÂÓ¼Æ»® Ç¿Á¬Í¨TarjanËõµã
//copyright by ametake
//Cheer up !!!
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

const int maxn=3000+5;
int n,t;
int head[maxn],to[maxn*maxn],nxt[maxn*maxn],et=0;
bool ins[maxn];
int dfn[maxn],low[maxn],sta[maxn],stp=0,tot=0;//stp is the point of stack ans tot is the number of the strongly connected components
int dep;
bool f = 0;
stack<int> big;

inline void add(int x,int y)
{
    et++;
    to[et]=y;
    nxt[et]=head[x];
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
    int temp;
    memset(head, 0, sizeof(head));
    memset(to, 0, sizeof(to));
    memset(nxt, 0, sizeof(nxt));
    memset(ins, 0, sizeof(ins));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sta, 0, sizeof(sta));
    dep = 0;
    stp = 0;
    tot = 0;
    et = 0;
    while (!big.empty()) big.pop();
    for (int i = 1;i <= n - 1;i++) { 
        for (int j = 1;j <= n - i;j++) {
            temp = read();
            if (temp == 1) {
                add(i, i+j);
                add(i+j, i);
            }
        }
    }
    return;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++dep;
    sta[++stp]=x;
    ins[x]=true;
    int t;
    for (t=head[x];t!=0;t=nxt[t])
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
        // printf("tot: %d\n", tot);
        int j;
        int now = 0;
        do
        {
            j=sta[stp--];
            ins[j]=false;
            now ++;
            // printf("%d now: %d\n", j, now);
            if (now >= 3){
                f = 1;
                // printf("now: %d f: %d\n", now, f);
                printf("Bad Team!\n");
                return;
            }
        }while (j!=x);
    }
    return;
}


int main()
{
    // freopen("1.txt","r",stdin);
    scanf("%d", &t);
    while (t--){
        init();
        for (int i=1;i<=n;i++) if (!dfn[i] && !f) tarjan(i);
        if (!f) printf("Great Team!\n");
    }
    return 0;
}
