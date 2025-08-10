/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 18:27:34
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 32, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> ops(N), score(N);
    ops[1] = score[1] = 1;
    for (int64_t i = 2, s = 1; i < N; ++i) {
        ops[i] = ops[i - 1] * 2;
        score[i] = s * i % MOD;
        s = s * score[i] % MOD;
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int64_t k; cin >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        while ((int)a.size() > 2 && a[(int)a.size() - 2] >= N) { a.pop_back(); }
        n = (int)a.size();
        int64_t ans = 1;
        while (k) {
            if (a[0] >= N || ops[a[0]] > k) {
                ans *= a[0]; ans %= MOD; k--;
                vector<int64_t> b;
                for (int i = 1; i < min(a[0], N); ++i) {
                    b.push_back(i);
                }
                for (int i = 1; i < n; ++i) {
                    b.push_back(a[i]);
                }
                a = b; n = (int)a.size();
            } else {
                ans *= score[a[0]]; ans %= MOD; k -= ops[a[0]];
                vector<int64_t> b;
                for (int i = 1; i < n; ++i) {
                    b.push_back(a[i]);
                }
                a = b; n = (int)a.size();
            }
        }
        cout << ans << "\n";
    }
}
