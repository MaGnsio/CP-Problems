/**
 *    author:  MaGnsi0
 *    created: 06.11.2023 12:11:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 9;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        set<int> s;
        for (int j = 0; j < n; ++j) {
            s.insert(a[i][j]);
        }
        ok = ok && (int)s.size() == 9;
    }
    for (int j = 0; j < n; ++j) {
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i][j]);
        }
        ok = ok && (int)s.size() == 9;
    }
    for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < n; j += 3) {
            set<int> s;
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    s.insert(a[i + k][j + l]);
                }
            }
            ok = ok && (int)s.size() == 9;
        }
    }
    cout << (ok ? "Yes" : "No");
}
