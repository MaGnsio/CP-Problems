/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 15:07:32
**/
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    bitset<N> a(0), b(0), take(0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x] = 1; b[N - x - 1] = 1;
    }
    int64_t ans = 0;
    for (int i = 1; i < N; ++i) {
        if (a[i] == 0) { take[i] = 1; continue; }
        int shift = (N - i - 2) - (i - 1);
        if (shift >= 0) {
            ans += (a & (b >> shift) & take).count();
        } else {
            ans += (a & (b << abs(shift)) & take).count();
        }
        take[i] = 1;
    }
    cout << ans;
}
