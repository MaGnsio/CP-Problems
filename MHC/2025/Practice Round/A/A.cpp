/**
 *    author:  MaGnsi0
 *    created: 11.10.2025 17:35:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        vector<set<int>> temps(n);
        vector<array<int, 3>> dishes(n);
        for (int i = 0; i < n; ++i) {
            cin >> dishes[i][0]; dishes[i][0]--;
            temps[dishes[i][0]].insert(i);
            dishes[i][2] = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> dishes[i][1]; dishes[i][1]--;
        }
        sort(dishes.begin(), dishes.end(), [](array<int, 3> x, array<int, 3> y) {
            return x[0] < y[0];
        });
        bool ok = true;
        vector<pair<int, int>> ops;
        for (int i = 0; i < n; ++i) {
            if (dishes[i][0] == dishes[i][1]) {
                continue;
            }
            if (dishes[i][0] > dishes[i][1] || temps[dishes[i][1]].empty()) {
                ok = false;
                break;
            }
            ops.emplace_back(dishes[i][2], *temps[dishes[i][1]].begin());
            temps[dishes[i][1]].insert(dishes[i][2]);
            temps[dishes[i][0]].erase(dishes[i][2]);
        }
        if (ok) {
            cout << (int)ops.size() << "\n";
            for (auto [x, y] : ops) {
                cout << x + 1 << " " << y + 1 << "\n";
            }
        } else {
            cout << "-1\n";
        }
    }
}
