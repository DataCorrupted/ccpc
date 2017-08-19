//黄学长全排列 递归标准模板 小数据 
#include<iostream>
#include<cstdio>
using namespace std;
int n;
int pd[11],used[11];
void print()
{
    for(int i=1;i<=n;i++)
        printf("%d ",used[i]);
    printf("\n");
}
void search(int k)
{
    if(k==n){print();return;}
    for(int i=1;i<=n;i++)
    {
        if(!pd[i]){pd[i]=1;used[k+1]=i;search(k+1);pd[i]=0;}
    }
}
int main()
{
    cin>>n;
    search(0);
    return 0;
}
