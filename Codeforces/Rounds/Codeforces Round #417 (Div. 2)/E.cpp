/**
 *    author:  MaGnsi0
 *    created: 27.09.2022 19:07:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1, j; i < n; ++i) {
        cin >> j;
        adj[i].push_back(j - 1);
        adj[j - 1].push_back(i);
    }
    queue<int> q;
    vector<int> parity(n, -1);
    for (int i = 1; i < n; ++i) {
        if ((int)adj[i].size() == 1) {
            q.push(i);
            parity[i] = 0;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& u : adj[v]) {
            if (parity[u] == -1) {
                q.push(u);
                parity[u] = parity[v] ^ 1;
            }
        }
    }
    int nimber = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        nimber ^= (parity[i] == 0) * a[i];
        mp[a[i]] += parity[i] == 1;
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        if (parity[i] == 0) {
            ans += mp[nimber ^ a[i]];
        }
    }
    if (nimber == 0) {
        int64_t cnt = count(parity.begin(), parity.end(), 0);
        ans += cnt * (cnt - 1) / 2;
        ans += (n - cnt) * (n - cnt - 1) / 2;
    }
    cout << ans;
}
