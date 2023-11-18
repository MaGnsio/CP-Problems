/**
 *    author:  MaGnsi0
 *    created: 24.10.2023 05:13:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<string, vector<pair<int, int>>> R;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s = "";
            for (int k = j; j < m && (int)s.size() < 16; ++k) {
                s += a[i][k];
                sort(s.begin(), s.end());
                R[s].emplace_back(i, j);
            }
        }
    }
    map<string, vector<pair<int, int>>> C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s = "";
            for (int k = i; k < n && (int)s.size() < 16; ++k) {
                s += a[k][j];
                sort(s.begin(), s.end());
                C[s].emplace_back(i, j);
            }
        }
    }
    map<string, vector<pair<int, int>>> DP;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s = "";
            for (int k = i, l = j; k < n && l < m && (int)s.size() < 16; ++k, ++l) {
                s += a[k][l];
                sort(s.begin(), s.end());
                DP[s].emplace_back(i, j);
            }
        }
    }
    map<string, vector<pair<int, int>>> DM;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s = "";
            for (int k = i, l = j; k >= 0 && l < m && (int)s.size() < 16; --k, ++l) {
                s += a[k][l];
                sort(s.begin(), s.end());
                DM[s].emplace_back(i, j);
            }
        }
    }
    vector<vector<int>> F(n, vector<int>(m));
    int Q; cin >> Q;
    while (Q--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        vector<vector<bool>> mark(n, vector<bool>(m));
        for (auto [x, y] : R[s]) {
            for (int i = 0; i < (int)s.size(); ++i) {
                mark[x][y + i] = true;
            }
        }
        for (auto [x, y] : C[s]) {
            for (int i = 0; i < (int)s.size(); ++i) {
                mark[x + i][y] = true;
            }
        }
        for (auto [x, y] : DP[s]) {
            for (int i = 0; i < (int)s.size(); ++i) {
                mark[x + i][y + i] = true;
            }
        }
        for (auto [x, y] : DM[s]) {
            for (int i = 0; i < (int)s.size(); ++i) {
                mark[x - i][y + i] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                F[i][j] += mark[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += F[i][j] > 1;
        }
    }
    cout << ans;
}
