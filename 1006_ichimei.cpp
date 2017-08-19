#include <iostream>
using namespace std;
#define MAX 100001
#define MOD 1000000007
int main() {
    int t, s[MAX], type;
    long n, q, l, r;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> q;
        cin.get();
        for (long j = 1; j <= n; j++) {
            s[j] = cin.get() - 48;
        }
        for (long j = 0; j < q; j++) {
            cin >> type >> l >> r;
            if (type == 1) {
                for (long k = l; k <= r; k++) {
                    s[k] = !s[k];
                }
            } else {
                long long dis[MAX] = {0};
                long last[2] = {0};
                for (long k = l; k <= r; k++) {
                    if (last[s[k]] == 0) {
                        dis[k] = (dis[k-1] * 2 + 1) % MOD;
                    } else {
                        dis[k] = (dis[k-1] * 2 - dis[last[s[k]]-1] + MOD) % MOD;
                    }
                    last[s[k]] = k;
                }
                cout << dis[r] << endl;
            }
        }
    }
    return 0;
}
