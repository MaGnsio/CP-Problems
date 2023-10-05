/**
 *    author:  MaGnsi0
 *    created: 31.01.2022 23:26:30
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;

vector<int> steps(N, -1);

void preprocess() {
    queue<int> q;
    steps[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= v; ++i) {
            int u = v + (v / i);
            if (u < N && steps[u] == -1) {
                steps[u] = steps[v] + 1;
                q.push(u);
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    preprocess();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = steps[a[i]];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<int> dp(k + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = k; j >= a[i]; --j) {
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
        cout << dp[k] << "\n";
    }
}
