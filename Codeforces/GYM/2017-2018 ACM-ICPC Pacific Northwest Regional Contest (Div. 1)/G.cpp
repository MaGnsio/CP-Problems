/**
 *    author:  MaGnsi0
 *    created: 10.11.2022 06:11:16
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int S, E;
    cin >> S >> E;
    vector<tuple<int, int, int, int>> A(M);
    for (int i = 0; i < M; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        A[i] = make_tuple(u - 1, v - 1, l, r);
    }
    vector<vector<tuple<int, int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        adj[get<0>(A[i])].push_back(make_tuple(get<1>(A[i]), get<2>(A[i]), get<3>(A[i])));
    }
    vector<int> B;
    for (int i = 0; i < M; ++i) {
        B.push_back(get<2>(A[i]));
        B.push_back(get<3>(A[i]));
    }
    sort(B.begin(), B.end());
    B.resize(unique(B.begin(), B.end()) - B.begin());
    function<int(int)> go = [&](int L) {
        vector<int> C(N, -1);
        priority_queue<pair<int, int>> Q;
        C[S - 1] = OO;
        Q.push(make_pair(C[S - 1], S - 1));
        while (!Q.empty()) {
            int v = Q.top().second;
            int R = Q.top().first;
            Q.pop();
            for (auto& [u, l, r] : adj[v]) {
                if (L < l || L > r) {
                    continue;
                }
                int bestR = min(R, r); 
                if (C[u] < bestR) {
                    C[u] = bestR;
                    Q.push(make_pair(C[u], u));
                }
            }
        }
        return C[E - 1];
    };
    int end = B[0];
    vector<int> ansL, ansR;
    for (int i = 0; i < (int)B.size(); ++i) {
        if (B[i] == end) {
            int X = go(B[i]);
            if (X == -1) {
                end = (i + 1 < (int)B.size() ? B[i + 1] : -1);
            } else {
                ansL.push_back(B[i]);
                ansR.push_back(X);
                if (X == B[i]) {
                    end = B[i + 1];
                } else {
                    end = X;
                }
            }
        }
    }
    if (ansL.empty()) {
        cout << 0 << "\n";
        return 0;
    }
    int curL = ansL[0], curR = ansR[0], ans = 0;
    for (int i = 1; i < (int)ansL.size(); ++i) {
        if (ansL[i] <= curR) {
            curR = ansR[i];
        } else {
            ans += curR - curL + 1;
            curL = ansL[i], curR = ansR[i];
        }
    }
    ans += curR - curL + 1;
    cout << ans;
}
