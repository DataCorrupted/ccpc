//codevs1166 ����ȡ����Ϸ ����DP+�߾� 
//copyright by ametake
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=80+5;
int n,m;
//int a[maxn];//�����ǷǸ߾��ඨ�� 

char a[maxn],b[maxn];

const int power=4;
const int base=10000;
const int maxl=10;

/*
*��Ҫ�õ�
  *�߾��Ӹ߾���״̬ת��ʱ��������飩
  *�߾��ӵ�����״̬ת��ʱa[k]+f[i][j]�� 
  *���صȺ� ���ڰ�int��ֵ���ṹ�� 
  *��f���鿪�ɽṹ�壬ÿ���ṹ�嶼��һ���߾���
  *����ͨ������룬�߾�����
  *���Գ���һ�£���д������� 
*/

struct num
{
    int a[maxl];
    
    num()
    {
         memset(a,0,sizeof(a));
    }
    
    num(char *s)                                            //��һ���ַ�����ʼ��Ϊ�߾�����  
    {  
        memset(a, 0, sizeof(a));  
        int len = strlen(s);  
        a[0] = (len+power-1) / power;                       //���ĳ���  
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
    
    num operator + (const int &b)//this->������ʡ�� 
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
    
    bool operator < (const num &b)const//�����const 
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
        //�ȴ�ӡ���λ��Ϊ��ѹλ ���� �ø߾�����Ϊ0 ����  
        for (int i = a[0]-1;i > 0;--i)  
        printf("%0*d", power, a[i]);    
        //����"%0*d", power����˼�ǣ��������powerλ��������ǰ����0����  
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
