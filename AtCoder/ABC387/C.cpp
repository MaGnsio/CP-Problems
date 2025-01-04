/**
 *    author:  MaGnsi0
 *    created: 04.01.2025 14:27:38
**/
#include <bits/stdc++.h>

using namespace std;

int64_t F(int64_t x) {
    string s = to_string(x);
    int n = (int)s.size();
    if (n == 1) { return 0; }
    int64_t res = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == n) { res++; break; }
        int64_t add = min(s[i] - '0', s[0] - '0');
        for (int j = i + 1; j < n; ++j) {
            add *= int64_t(s[0] - '0');
        }
        res += add;
        if (s[i] >= s[0]) { break; }
    }
    for (int64_t last_d = 1; last_d < s[0] - '0'; ++last_d) {
        int64_t add = 1;
        for (int i = 1; i < n; ++i) {
            add *= last_d;
        }
        res += add;
    }
    for (int m = 2; m < n; ++m) {
        for (int64_t last_d = 1; last_d <= 9; ++last_d) {
            int64_t add = 1;
            for (int i = 1; i < m; ++i) {
                add *= last_d;
            }
            res += add;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t L; cin >> L;
    int64_t R; cin >> R;
    int64_t ans = F(R) - F(L - 1);
    cout << ans;
}
