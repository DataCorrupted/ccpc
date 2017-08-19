#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> kbase(long n, int k) {
    vector<int> v = {};
    while (n > 0) {
        v.push_back(n % k);
        n = n / k;
    }
    return v;
}

long intbase(vector<int> v, int k) {
    long ans = 0;
    while (v.size() > 0) {
        ans *= k;
        ans += v[v.size()-1];
        v.pop_back();
    }
    return ans;
}

long count(vector<int> vl, vector<int> vr, int k) {
    vector<int> halfvl, halfvr;
    int size = vl.size();
    int statl = 0, statr = 0;
    for (int i = (size-2)/2; i >= 0; i--) {
        if (vl[i] > vl[size-1-i]) {
            statl = 1;
            break;
        } else if (vl[i] < vl[size-1-i])
            break;
    }
    for (int i = (size-1)/2; i >= 0; i--) {
        halfvl.push_back(vl[size-1-i]);
    }
    for (int i = (size-2)/2; i >= 0; i--) {
        if (vr[i] < vr[size-1-i]) {
            statr = 1;
            break;
        } else if (vr[i] > vr[size-1-i])
            break;
    }
    for (int i = (size-1)/2; i >= 0; i--) {
        halfvr.push_back(vr[size-1-i]);
    }
    return intbase(halfvr, k) - statr - intbase(halfvl, k) - statl + 1;
}

vector<int> kmin(int size, int k) {
    vector<int> v;
    for (int i = 1; i < size; i++)
        v.push_back(0);
    v.push_back(1);
    return v;
}

vector<int> kmax(int size, int k) {
    vector<int> v;
    for (int i = 1; i <= size; i++)
        v.push_back(k-1);
    return v;
}

int main() {
    long t, L, R;
    int l, r;
    cin >> t;
    for (long k = 1; k <= t; k++) {
        cin >> L >> R >> l >> r;
        long ans = 0;
        for (int j = l; j <= r; j++) {
            long num = 0;
            ans += R - L + 1;
            vector<int> vl = kbase(L, j);
            vector<int> vr = kbase(R, j);
            int vls = vl.size();
            int vrs = vr.size();
            if (vls == vrs) {
                num += count(vl, vr, j);
            } else {
                num += count(vl, kmax(vls, j), j);
                for (int n = vls + 1; n < vrs; n++) {
                    int p = (n-1)/2;
                    num += pow(j, p+1) - pow(j, p);
                }
                num += count(kmin(vrs, j), vr, j);
            }
            ans += (j - 1) * num;
        }
        cout << "Case #" << k << ": " << ans << endl;
    }
    return 0;
}
