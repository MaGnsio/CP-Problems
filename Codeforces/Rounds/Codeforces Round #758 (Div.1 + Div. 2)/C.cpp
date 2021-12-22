/**
 *    author:  MaGnsi0
 *    created: 13.12.2021 17:04:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(b.begin(), b.end());
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[a[i - 1].second].push_back(a[i].second);
            adj[b[i - 1].second].push_back(b[i].second);
        }
        vector<int> dp(n, -1);
        queue<int> q;
        dp[a[n - 1].second] = 0;
        q.push(a[n - 1].second);
        dp[b[n - 1].second] = 0;
        q.push(b[n - 1].second);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& u : adj[v]) {
                if (dp[u] == -1) {
                    dp[u] = 0;
                    q.push(u);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << dp[i] + 1;
        }
        cout << "\n";
    }
}
