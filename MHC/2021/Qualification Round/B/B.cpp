/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 14:09:46
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<vector<char>> g(n, vector<char>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> g[i][j];
            }
        }
        set<set<pair<int, int>>> s;
        for (int i = 0; i < n; ++i) {
            bool valid = true;
            set<pair<int, int>> temp;
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 'O') {
                    valid = false;
                    break;
                } else if (g[i][j] == '.') {
                    temp.insert({i, j});
                }
            }
            if (valid) {
                s.insert(temp);
            }
        }
        for (int j = 0; j < n; ++j) {
            bool valid = true;
            set<pair<int, int>> temp;
            for (int i = 0; i < n; ++i) {
                if (g[i][j] == 'O') {
                    valid = false;
                    break;
                } else if (g[i][j] == '.') {
                    temp.insert({i, j});
                }
            }
            if (valid) {
                s.insert(temp);
            }
        }
        cout << "Case #" << t << ": ";
        if (s.empty()) {
            cout << "Impossible\n";
        } else {
            int mini = INT_MAX, cnt = 0;
            for (auto& k : s) {
                mini = min(mini, (int)k.size());
            }
            for (auto& k : s) {
                cnt += (k.size() == mini);
            }
            cout << mini << " " << cnt << "\n";
        }
    }
}
