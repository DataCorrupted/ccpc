//���ر�����д��д������Ҿ�д��ҵȥ��������flag���������������������������������Լ����Լ������ˣ�
//logm��ʱ�䴦��һ�����ر����е���Ʒ�ķ��� 

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

//����01��������ȫ���� ֻ��Ҫ�ڸ��Գ�����������һ��ö����Ʒ��ѭ������ 
