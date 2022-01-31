/**
 *    author:  MaGnsi0
 *    created: 22.12.2021 19:49:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long r, res = 0;
    cin >> r;
    vector<bool> a(r * r + 1, false);
    for (long long i = 0; i <= r; ++i) {
        a[i * i] = true;
    }
    for (long long i = -r; i <= r; ++i) {
        for (long long j = -r; j <= r; ++j) {
            long long k = (r * r) - (i * i) - (j * j);
            if (k >= 0) {
                res += (k == 0 ? 1 : 2 * a[k]);
            }
        }
    }
    cout << res;
}
