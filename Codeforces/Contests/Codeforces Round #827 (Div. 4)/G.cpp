/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:58:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<vector<int>> b(31);
        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((a[j] >> i) & 1) {
                    b[i].push_back(j);
                }
            }
        }
        vector<int> c;
        vector<bool> visited(n, false), done(32, false);
        for (int i = 30; i >= 0; --i) {
            if (done[i]) {
                continue;
            }
            set<pair<int64_t, int>> s;
            for (int j = 0; j < (int)b[i].size(); ++j) {
                if (visited[b[i][j]]) {
                    continue;
                }
                int64_t X = 0;
                for (int k = 0; k < 31; ++k) {
                    if (!done[k] && ((a[b[i][j]] >> k) & 1)) {
                        X |= (1 << k);
                    }
                }
                s.insert(make_pair(X, b[i][j]));
            }
            if (s.empty()) {
                continue;
            }
            int64_t X = s.rbegin() -> first, j = s.rbegin() -> second;
            c.push_back(j);
            visited[j] = true;
            for (int k = 0; k < 31; ++k) {
                if ((a[j] >> k) & 1) {
                    done[k] = true;
                }
            }
        }
        for (int i = 0; i < (int)c.size(); ++i) {
            cout << a[c[i]] << " ";
        }
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
}
