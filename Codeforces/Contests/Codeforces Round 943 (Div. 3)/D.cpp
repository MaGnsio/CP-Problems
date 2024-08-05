/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 14:18:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int p1; cin >> p1; p1--;
        int p2; cin >> p2; p2--;
        vector<int64_t> p(n), a(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i]; p[i]--;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        function<int64_t(int)> F = [&](int start) {
            int v = start, t = k;
            int64_t s = 0, h = 0;
            vector<bool> done(n, false);
            while (t && !done[v]) {
                done[v] = true;
                s = max(s, t * a[v] + h);
                h += a[v], v = p[v], t--;
            }
            return s;
        };
        int64_t s1 = F(p1);
        int64_t s2 = F(p2);
        cout << (s1 == s2 ? "Draw" : (s1 > s2 ? "Bodya" : "Sasha")) << "\n";
    }
}
