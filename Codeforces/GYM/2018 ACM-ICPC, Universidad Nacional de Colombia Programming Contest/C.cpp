/**
 *    author:  MaGnsi0
 *    created: 09.11.2021 13:17:16
**/
#include <bits/stdc++.h>

using namespace std;

const long long N = 128, OO = 1e10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n;
    cin >> n;
    vector<vector<long long>> g(N, vector<long long>(N, OO));
    for (int i = 0; i < N; ++i) {
        g[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        long long w;
        char u, v;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(g[s[i]][t[i]] == OO) {
            cout << -1;
            return 0;
        }
        res += g[s[i]][t[i]];
    }
    cout << res;
}
