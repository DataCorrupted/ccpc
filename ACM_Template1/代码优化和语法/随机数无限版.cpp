#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));//Linux���ȶ� ����ȡһ��ȷ����ֵ ������8�ǿ��Ե� 
	int n; 
	cin>>n;
	while (n!=0){
		cout<<rand()%n;
		cin>>n;
	}
	return 0;
}
