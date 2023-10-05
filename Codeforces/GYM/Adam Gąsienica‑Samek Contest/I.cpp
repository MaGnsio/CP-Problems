/**
 *    author:  MaGnsi0
 *    created: 02.09.2023 22:11:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int M; cin >> M;
    int Q; cin >> Q;
    vector<int> c(N);
    for (int i = 0; i < N; ++i) {
        cin >> c[i];
    }
    vector<int> b = c;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int K = (int)b.size();
    for (int i = 0; i < N; ++i) {
        int j = lower_bound(b.begin(), b.end(), c[i]) - b.begin();
        c[i] = K - j - 1;
    }
    vector<int> maxC(K);
    iota(maxC.begin(), maxC.end(), 0);
    for (int i = 0; i < M; ++i) {
        int u; cin >> u; u = c[u - 1];
        int v; cin >> v; v = c[v - 1];
        if (u > v) { swap(u, v); }
        maxC[u] = max(maxC[u], v);
    }
    for (int i = 1; i < K; ++i) {
        maxC[i] = max(maxC[i], maxC[i - 1]);
    }
    int LG = __lg(K) + 1;
    vector<vector<int>> S(LG, vector<int>(K));
    S[0] = maxC;
    for (int i = 1; i < LG; ++i) {
        for (int j = 0; j < K; ++j) {
            S[i][j] = S[i - 1][S[i - 1][j]];
        }
    }
    for (int q = 0; q < Q; ++q) {
        char _; cin >> _;
        int u; cin >> u; u = c[u - 1];
        int v; cin >> v; v = c[v - 1];
        int ans = 0;
        if (u <= v) {
            ans = 0;
        } else {
            swap(u, v);
            for (int i = LG - 1; i >= 0; --i) {
                if (S[i][u] < v) {
                    u = S[i][u];
                    ans += 1 << i;
                }
            }
            u = S[0][u]; ans++;
            if (u < v) { ans = -1; }
        }
        cout << ans << "\n";
    }
}
