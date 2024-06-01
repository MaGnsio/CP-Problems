/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 15:19:47
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(N);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; a[x]++;
    }
    int64_t ans = -n;
    for (int i = 0; i < N; ++i) {
        ans -= 1LL * a[i] * (a[i] - 1) / 2;
    }
    for (int i = 1; i < N; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i < N; ++i) {
        int m = a[i] - a[i - 1];
        if (m == 0) { continue; }
        for (int j = 1; i * j < N; ++j) {
            int L = i * j - 1;
            int R = min(i * (j + 1) - 1, N - 1);
            ans += 1LL * m * j * (a[R] - a[L]);
        }
    }
    cout << ans;
}
