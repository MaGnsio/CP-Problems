/**
 *    author:  MaGnsi0
 *    created: 19.09.2024 23:24:02
**/
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    if (x == 1) { return false; }
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) { return false; }
    }
    return true;
}

vector<int> F(int n) {
    vector adj(n, vector<int>(n, 1));
    if (n % 2 == 0) {
        for (int i = 1; i < n - 2; i += 2) {
            adj[i][i + 1] = adj[i + 1][i] = 0;
        }
    }
    vector<int> path, l(n, 0);
    function<void(int)> dfs = [&](int v) {
        for (int& u = l[v]; u < n; ++u) {
            if (adj[u][v] == 0) { continue; }
            adj[u][v] = adj[v][u] = 0;
            dfs(u);
        }
        path.push_back(v);
    };
    dfs(0);
    return path;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N = 0;
    vector<int> V;
    for (int v = 2; v <= 3e5 && 1LL * N * (N - 1) <= 2e6; ++v) {
        if (is_prime(v)) {
            V.push_back(v);
            N++;
        } 
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int low = 1, high = N, m = N;
        while (low <= high) {
            int mid = (low + high) / 2;
            int l = (mid & 1 ? mid * (mid + 1) / 2 + 1 : mid * mid / 2 + 2);
            if (l >= n) {
                m = mid; high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        vector<int> ans = F(m);
        for (int i = 0; i < n; ++i) {
            ans[i] = V[ans[i]];
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
