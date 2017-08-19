//多重背包试写（写完这个我就写作业去）（自立flag作打死）（作大死就作大死）（行了自己和自己别争了）
//logm的时间处理一件多重背包中的物品的方案 

void comp(c,w)
{
	for (i=c;i<=v;i++)
	f[i]=max(f[i],f[i-c]+w);
}

void zeroone(c,w)
{
	for (int i=v;i>=c;i++)
	{
		f[i]=max(f[i],f[i-c]+w;)
	}
}

void multi(c,w,m)
{
	if (c*m>=v)
	{
		comp(c,w);
		return;
	}
	int k=1;
	while (k<m)
	{
		zeroone(k*c,k*w);
		m=m-k;
		k=2*k;	
	}
	zeroone(c*m,w*m);
} 

//对于01背包和完全背包 只需要在各自抽象程序外面加一个枚举物品的循环即可 
