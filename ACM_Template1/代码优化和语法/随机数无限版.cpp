#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

int main(){
	srand(time(NULL));//Linux不稳定 可以取一个确定的值 经检验8是可以的 
	int n; 
	cin>>n;
	while (n!=0){
		cout<<rand()%n;
		cin>>n;
	}
	return 0;
}
