/**
 *    author:  MaGnsi0
 *    created: 19.12.2023 12:35:03
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M; cin >> M;
    vector<int> F(N);
    function<bool(int64_t)> check = [&](int64_t x) {
        vector<int> f = F;
        for (int i = 0; i < N; ++i) {
            if (x >> i & 1) {
                if (f[i]) {
                    f[i]--;
                } else {
                    return false;
                }
            }
            if (i + 1 < N) {
                f[i + 1] += f[i] / 2;
            }
        }
        return true;
    };
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; F[x]++;
        } else {
            int x; cin >> x;
            cout << (check(x) ? "YES" : "NO") << "\n";
        }
    }
}
