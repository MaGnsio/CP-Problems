/**
 *    author:  MaGnsi0
 *    created: 30.04.2022 16:34:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<vector<int>> a(n, vector<int>(26, 0));
        for (int i = 0; i < n; ++i) {
            a[i][s[i] - 'a']++;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                a[i][j] += a[i - 1][j];
            }
        }
        vector<vector<int>> b(26);
        for (int i = 0; i < n; ++i) {
            b[s[i] - 'a'].push_back(i);
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j < (int)b[i].size(); ++j) {
                int l = b[i][j - 1], r = b[i][j];
                for (int k = 0; k < 26; ++k) {
                    if (k == i || a[n - 1][k] == 0) {
                        continue;
                    }
                    if (a[r][k] - a[l][k] == 0) {
                        ok = false;
                    }
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
