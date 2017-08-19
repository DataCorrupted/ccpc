//codevs1166 矩阵取数游戏 区间DP+高精 
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=80+5;
int n,m;
//int a[maxn];//以上是非高精类定义 

char a[maxn],b[maxn];

const int power=4;
const int base=10000;
const int maxl=10;

/*
*需要用到
  *高精加高精（状态转移时数组加数组）
  *高精加单精（状态转移时a[k]+f[i][j]） 
  *重载等号 用于把int赋值给结构体 
  *把f数组开成结构体，每个结构体都是一个高精数
  *按普通数组读入，高精处理
  *可以尝试一下，先写出来框架 
*/

struct num
{
    int a[maxl];
    
    num()
    {
         memset(a,0,sizeof(a));
    }
    
    num(char *s)                                            //将一个字符串初始化为高精度数  
    {  
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //数的长度  
        for (int i=0, t=0, w; i < len ;w *= 10, ++i)          
        {  
            if (i % power == 0) { w = 1, ++t; }  
            a[t] += w * (s[i]-'0');  
        }  
    }
    
    num operator + (const num &b)
    {
        num c;
        c.a[0]=max(a[0],b.a[0]);
        for (int i=1;i<=c.a[0];i++)
        {
            c.a[i]+=a[i]+b.a[i];
            c.a[i+1]+=c.a[i]/base;
            c.a[i]=c.a[i]%base;
        }
        if (c.a[c.a[0]+1])++c.a[0];  
        return c; 
    }
    
    num operator + (const int &b)//this->都可以省略 
    {
        this->a[1]+=b;
        int i=1;
        while (this->a[i]>=base)
        {
            this->a[i+1]+=this->a[i]/base;
            this->a[i]%=base;
            i++;
        }
        if (this->a[this->a[0]+1])this->a[0];  
        return *this;
    }
    
    num operator = (int b)
    {
        a[0]=0;
        while (b)
        {
            a[0]++;
            a[a[0]]=b%base;
            b/=base;
        }
        return *this;
    }
    
    bool operator < (const num &b)const//必须加const 
    {
        if (a[0] < b.a[0]) return true;  
        if (a[0] > b.a[0]) return false;  
        for (int i = a[0];i > 0;--i)  
        {  
            if (a[i] != b.a[i]) return a[i] < b.a[i];  
        }  
        return false;  
    }
    
    void print()
    {
        printf("%d", a[ a[0] ]);        
        //先打印最高位，为了压位 或者 该高精度数为0 考虑  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //这里"%0*d", power的意思是，必须输出power位，不够则前面用0补足  
        printf("\n"); 
    }
    
}ans,f[maxn][maxn],p,q;

int main()
{ 
    scanf("%s", a);  
    scanf("%s", b);  
    reverse(a, a+strlen(a));  
    reverse(b, b+strlen(b));  
  
    p = num(a), q = num(b);  
  
    ans = p + q;
    ans.print();
    ans = ans + 50;  
    ans.print();
    ans=12345;
    ans.print();
    while (1);
    return 0;
} 
