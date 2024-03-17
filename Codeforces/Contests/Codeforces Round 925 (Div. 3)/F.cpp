/**
 *    author:  MaGnsi0
 *    created: 13.02.2024 17:20:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<vector<int>> a(k, vector<int>(n));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j]; a[i][j]--;
            }
        }
        if (k == 1) {
            cout << "YES\n";
            continue;
        }
        vector<vector<int>> b(n);
        for (int i = 0; i < k; ++i) {
            for (int j = 1; j < n; ++j) {
                b[a[i][j]].push_back(j);
            }
        }
        for (int i = 0; i < n; ++i) {
            sort(b[i].begin(), b[i].end());
        }
        bool bad = false;
        vector<bool> done(n, false);
        for (int i = 0; i < n; ++i) {
            set<int> s(b[i].begin(), b[i].end());
            if ((int)s.size() == 2) {
                int x = *s.begin(), y = *s.rbegin();
                int cx = count(b[i].begin(), b[i].end(), x);
                int cy = count(b[i].begin(), b[i].end(), y);
                if (y - x != 1) {
                    bad = true;
                    break;
                }
                if (cx > x || cy > n - x - 1) {
                    bad = true;
                    break;
                }
                if (done[x]) {
                    bad = true;
                    break;
                }
                done[x] = true;
            } else if ((int)s.size() == 1) {
                continue;
            } else {
                bad = true;
                break;
            }
        }
        cout << (bad ? "NO" : "YES") << "\n";
    }
}
