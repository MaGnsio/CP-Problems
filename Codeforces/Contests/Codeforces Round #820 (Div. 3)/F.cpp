/**
 *    author:  MaGnsi0
 *    created: 12.09.2022 16:33:16
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
        int w, m, n = (int)s.size();
        cin >> w >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (s[i] - '0') % 9;
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            a[i] %= 9;
        }
        vector<vector<int>> mods(9);
        for (int i = w - 1; i < n; ++i) {
            int val = (a[i] - (i > w - 1 ? a[i - w] : 0) + 9) % 9;
            mods[val].push_back(i - w + 2);
        }
        for (int i = 0; i < m; ++i) {
            int l, r, K;
            cin >> l >> r >> K;
            int val = (a[r - 1] - (l - 2 >= 0 ? a[l - 2] : 0) + 9) % 9;
            pair<int, int> L = {-1, -1};
            for (int j = 0; j < 9; ++j) {
                for (int k = 0; k < 9; ++k) {
                    if (mods[j].empty() || mods[k].empty()) {
                        continue;
                    }
                    if (j == k && mods[j].size() < 2) {
                        continue;
                    }
                    int x = ((j * val) % 9 + k) % 9;
                    if (x == K) {
                        pair<int, int> temp = {mods[j][0], (j == k ? mods[j][1] : mods[k][0])};
                        if (L.first == -1) {
                            L = temp;
                        } else {
                            L = min(L, temp);
                        }
                    }
                }
            }
            cout << L.first << " " << L.second << "\n";
        }
    }
}
