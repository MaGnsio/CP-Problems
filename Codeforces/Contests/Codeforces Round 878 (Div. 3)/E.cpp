/**
 *    author:  MaGnsi0
 *    created: 06.06.2023 20:26:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<string> s(2);
        cin >> s[0] >> s[1];
        int h, q;
        int n = (int)s[0].size();
        cin >> h >> q;
        int not_equals = 0;
        set<pair<int, int>> blocked;
        for (int i = 0; i < n; ++i) {
            not_equals += s[0][i] != s[1][i];
        }
        for (int i = 1; i <= q; ++i) {
            int t;
            cin >> t;
            while ((!blocked.empty()) && (blocked.begin() -> first < i)) {
                int j = blocked.begin() -> second;
                not_equals += s[0][j] != s[1][j];
                blocked.erase(blocked.begin());
            }
            if (t == 1) {
                int j;
                cin >> j;
                blocked.emplace(i + h - 1, j - 1);
                not_equals -= s[0][j - 1] != s[1][j - 1];
            } else if (t == 2) {
                int j1, k1, j2, k2;
                cin >> j1 >> k1 >> j2 >> k2;
                j1--, k1--, j2--, k2--;
                if (j1 == j2 && k1 == k2) { continue; }
                not_equals -= s[0][k1] != s[1][k1]; 
                if (k1 != k2) {
                    not_equals -= s[0][k2] != s[1][k2];
                }
                swap(s[j1][k1], s[j2][k2]);
                not_equals += s[0][k1] != s[1][k1]; 
                if (k1 != k2) {
                    not_equals += s[0][k2] != s[1][k2];
                }
            } else {
                cout << (not_equals == 0 ? "YES" : "NO") << "\n";
            }
        }
    }
}
