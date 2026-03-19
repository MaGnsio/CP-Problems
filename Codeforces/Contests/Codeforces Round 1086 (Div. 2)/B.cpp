/**
 *    author:  MaGnsi0
 *    created: 19.03.2026 05:51:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int p; cin >> p; p--;
        int m; cin >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> q(n);
        iota(q.begin(), q.end(), 0);
        function<bool(int)> move = [&](int j) {
            if (a[q[j]] > m) { return false; }
            m -= a[q[j]]; ans += q[j] == p;
            vector<int> nq;
            for (int i = 0; i < n; ++i) {
                if (i == j) { continue; }
                nq.push_back(q[i]);
            }
            nq.push_back(q[j]);
            q = nq;
            return true;
        };
        while(true) {
            int to_pick = -1;
            for (int i = 0; i < k; ++i) {
                if (q[i] == p) { to_pick = i; break; }
            }
            if (to_pick != -1) {
                if (move(to_pick)) { continue; }
                else { break; }
            }
            for (int i = 0; i < k; ++i) {
                if (to_pick == -1 || a[q[to_pick]] > a[q[i]]) {
                    to_pick = i;
                }
            }
            if (move(to_pick)) { continue; }
            else { break; }
        }
        cout << ans << "\n";
    }
}
