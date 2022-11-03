/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 15:22:01
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
        int k, n;
        string s;
        cin >> s >> k;
        n = s.size();
        vector<vector<int>> adj(26, vector<int>(26, -1));
        for (int i = 0; i < k; ++i) {
            char u, v;
            cin >> u >> v;
            adj[u - 'A'][v - 'A'] = 1;
        }
        for (int i = 0; i < 26; ++i) {
            adj[i][i] = 0;
        }
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (adj[i][k] != -1 && adj[k][j] != -1) {
                        if (adj[i][j] == -1 || adj[i][j] > adj[i][k] + adj[k][j]) {
                            adj[i][j] = adj[i][k] + adj[k][j];
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (char c = 'A'; c <= 'Z'; ++c) {
            int cnt = 0;
            bool valid = true;
            for (int i = 0; i < n; ++i) {
                if (adj[s[i] - 'A'][c - 'A'] == -1) {
                    valid = false;
                    break;
                } else {
                    cnt += adj[s[i] - 'A'][c - 'A'];
                }
            }
            if (valid && (ans == -1 || ans > cnt)) {
                ans = cnt;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
