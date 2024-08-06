/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 18:11:37
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> F(N);
    for (int i = 1; i < N; ++i) {
        for (int x = i; x; x /= 3) { F[i]++; }
        F[i] += F[i - 1];
    }
    int T; cin >> T;
    while (T--) {
        int l; cin >> l;
        int r; cin >> r;
        int ans = F[r] - F[l - 1];
        for (int x = l; x; x /= 3) { ans++; }
        cout << ans << "\n";
    }
}
