#include<iostream>
#include<cstdio>
using namespace std;

main(){
	printf("%d\n",8/5);
	cout.setf(ios::fixed);
	cout.precision(0);
	cout<<8.0/5.0+0.5;//����ֱ��ǿ������ת�� (int)(XXX) 
	return 0;
}
