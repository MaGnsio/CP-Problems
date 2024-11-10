/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 16:35:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = (int)s.size();
        int have = 0;
        function<int(int)> F = [&](int j) {
            if (j < 0) { return 0; }
            if (j + 3 >= n) { return 0; }
            return int(s.substr(j, 4) == "1100");
        };
        function<void(int, int)> G = [&](int j, int sign) {
            for (int i = -3; i <= 3; ++i) {
                have += sign * F(j + i);
            }
        };
        for (int i = 0; i < n; ++i) {
            have += F(i);
        }
        int Q; cin >> Q;
        while (Q--) {
            int j; cin >> j; j--;
            char x; cin >> x;
            G(j, -1); s[j] = x; G(j, +1);
            cout << (have ? "YES" : "NO") << "\n";
        }
    }
}
