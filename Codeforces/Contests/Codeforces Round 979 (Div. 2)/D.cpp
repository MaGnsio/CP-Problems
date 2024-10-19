/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 17:27:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--;
        }
        string s; cin >> s;
        vector<set<int>> bad(2);
        vector need(2, vector<int>(n, 0));
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == 'L' && s[i + 1] == 'R') {
                bad[0].insert(i);
            }
            if (s[i] == 'L' && s[i + 1] == 'R') {
                bad[1].insert(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            int j = a[i]; //i ===> j
            if (i < j) { //no LR
                need[0][i]++; need[0][j]--;
            } else { //no LR
                need[1][j]++; need[1][i]--;
            }
        }
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j < n; ++j) {
                need[i][j] += need[i][j - 1];
            }
        }
        int state = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                state += need[i][j] && bad[i].count(j);
            }
        }
        function<void(int)> undo = [&](int k) {
            for (int i = 0; i < 2; ++i) {
                for (int j = max(k - 1, 0); j <= min(n - 2, k + 1); ++j) {
                    state -= need[i][j] && bad[i].count(j);
                    bad[i].erase(j);
                }
            }
        };
        function<void(int)> do_ = [&](int k) {
            for (int i = 0; i < 2; ++i) {
                for (int j = max(k - 1, 0); j <= min(n - 2, k + 1); ++j) {
                    if (s[j] == 'L' && s[j + 1] == 'R') {
                        bad[0].insert(j);
                    }
                    if (s[j] == 'L' && s[j + 1] == 'R') {
                        bad[1].insert(j);
                    }
                    state += need[i][j] && bad[i].count(j);
                }
            }
        };
        while (Q--) {
            int j; cin >> j; j--;
            undo(j);
            s[j] = (s[j] == 'L' ? 'R' : 'L');
            do_(j);
            cout << (state == 0 ? "YES" : "NO") << "\n";
        }
    }
}
