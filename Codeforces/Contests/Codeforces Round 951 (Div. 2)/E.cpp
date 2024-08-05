/**
 *    author:  MaGnsi0
 *    created: 09.06.2024 00:24:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int d; cin >> d;
        vector<int> X(n), Y(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            int y; cin >> y;
            X[i] = x - y;
            Y[i] = x + y;
        }
        int I = 0, J = 0, K = 0;
        function<void()> solve = [&]() {
            map<pair<int, int>, int> mp1;
            map<int, vector<pair<int, int>>> mp2;
            for (int i = 0; i < n; ++i) {
                mp1[make_pair(X[i], Y[i])] = i;
                mp2[Y[i]].emplace_back(X[i], i);
            }
            for (auto& [_, a] : mp2) {
                sort(a.begin(), a.end());
            }
            for (int i = 0; i < n; ++i) {
                int x1 = X[i], y1 = Y[i];
                for (int dx : {-d, d}) {
                    int x2 = x1 + dx, y2 = y1;
                    if (mp1.find(make_pair(x2, y2)) == mp1.end()) { continue; }
                    for (int dy : {-d, d}) {
                        int y3 = y1 + dy;
                        auto it = lower_bound(mp2[y3].begin(), mp2[y3].end(), make_pair(min(x1, x2), 0));
                        if (it == mp2[y3].end() || it -> first > max(x1, x2)) { continue; }
                        I = i + 1, J = mp1[make_pair(x2, y2)] + 1, K = it -> second + 1;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                swap(X[i], Y[i]);
            }
        };
        solve(); solve();
        cout << I << " " << J << " " << K << "\n";
    }
}
