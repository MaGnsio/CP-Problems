/**
 *    author:  MaGnsi0
 *    created: 22/07/2021 18:06:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> cnt(n, 0);
        for (int i = 0; i < n; ++i) {
            int k = (i - p[i] + n) % n;
            cnt[k]++;
        }
        auto ok = [=] (int k) {
            vector<int> q;
            for (int j = k; j < n; ++j) {
                q.push_back(p[j]);
            }
            for (int j = 0; j < k; ++j) {
                q.push_back(p[j]);
            }
            int cc = 0;
            vector<bool> used(n, false);
            for (int i = 0; i < n; ++i) {
                if (used[i]) {
                    continue;
                }
                int x = i;
                while (!used[x]) {
                    used[x] = true;
                    x = q[x];
                }
                cc++;
            }
            return (n - cc <= m);
        };
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (n - cnt[i] <= 2 * m && ok(i)) {
                res.push_back(i);
            }
        }
        cout << res.size() << " ";
        for (auto& x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
