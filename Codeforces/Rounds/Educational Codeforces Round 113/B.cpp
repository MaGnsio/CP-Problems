/**
 *    author:  MaGnsi0
 *    created: 08/09/2021 16:07:20
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '2') {
                v.push_back(i);
            }
        }
        if ((int)v.size() == 1 || (int)v.size() == 2) {
            cout << "NO\n";
            continue;
        }
        vector<vector<char>> g(n, vector<char>(n, '='));
        for (int i = 0; i < (int)v.size(); ++i) {
            int j = (i + 1) % ((int)v.size());
            g[v[i]][v[j]] = '+';
            g[v[j]][v[i]] = '-';
        }
        for (int i = 0; i < n; ++i) {
            g[i][i] = 'X';
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
}
