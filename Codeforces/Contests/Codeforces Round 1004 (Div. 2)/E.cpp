/**
 *    author:  MaGnsi0
 *    created: 13.02.2025 21:14:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int zcnt = count(a.begin(), a.end(), 0);
        if (zcnt == 0) {
            cout << n << "\n";
            continue;
        }
        vector<int> b;
        for (int i = 0, got_zero = 0; i < n; ++i) {
            if (!a[i] && got_zero) { continue; }
            b.push_back(a[i]);
            got_zero |= a[i] == 0;
        }
        function<bool(vector<int>)> is_magical = [](vector<int> a) {
            int n = (int)a.size();
            vector<int> pmin(n), smex(n);
            pmin[0] = a[0];
            for (int i = 1; i < n; ++i) {
                pmin[i] = min(pmin[i - 1], a[i]);
            }
            set<int> s;
            for (int i = n - 1, m = 0; i >= 0; --i) {
                s.insert(a[i]);
                while (s.count(m)) { m++; }
                smex[i] = m;
            }
            for (int i = 0; i + 1 < n; ++i) {
                if (pmin[i] < smex[i + 1]) { return false; }
            }
            return true;
        };
        int ans = n - zcnt + is_magical(b);
        cout << ans << "\n";
    }
}
