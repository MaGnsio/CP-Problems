/**
 *    author:  MaGnsi0
 *    created: 23/07/2021 16:29:41
**/
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return (a.first - a.second > b.first - b.second);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, ans = 0;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(6, 0));
        vector<int> f(5, 0);
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (auto& c : s) {
                v[i][c - 'a']++;
                f[c - 'a']++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                v[i][5] += v[i][j];
            }
        }
        for (int i = 0; i < 5; ++i) {
            if (!f[i]) {
                continue;
            }
            int x = 0, y = 0;
            for (auto& o : f) {
                y += o;
            }
            y -= f[i];
            x = f[i];
            vector<pair<int, int>> p;
            for (int j = 0; j < n; ++j) {
                p.push_back({v[j][5] - v[j][i], v[j][i]});
            }
            sort(p.begin(), p.end(), comp);
            int cur = n;
            for (auto& [a, b] : p) {
                if (x > y) {
                    break;
                }
                x -= b;
                y -= a;
                cur--;
            }
            ans = max(ans, cur);
        }
        cout << ans << "\n";
    }
}
