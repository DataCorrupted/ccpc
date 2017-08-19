#include <iostream>
#include <cmath>

using namespace std;

int sqr(int k){ return k*k; }

int main(){
	int t;
	cin >> t;
	while (t--) {
		int toy = 0;
		cin >> toy;
		int k = sqrt((toy+1)/2);
			 if (2*sqr(k) >= toy) { cout << 4*k << endl; }
		else if (2*sqr(k)+k-1 >= toy) { cout << 4*k+1 << endl; }
		else if (2*sqr(k)+2*k >= toy) { cout << 4*k+2 << endl; }
		else if (2*sqr(k)+3*k >= toy) { cout << 4*k+3 << endl; }
		else 						  { cout << 4*k+4 << endl; }
	}
	return 0;
}