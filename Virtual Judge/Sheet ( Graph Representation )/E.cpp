//https://vjudge.net/contest/372876#problem/E
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<int> C(N);
    map<int, unordered_set<int>> Q;
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (C[u - 1] == C[v - 1]) {
            continue;
        }
        Q[C[u - 1]].insert(C[v - 1]);
        Q[C[v - 1]].insert(C[u - 1]);
    }
    int q = 0, n = *min_element(C.begin(), C.end());
    for (auto& x : Q) {
        if ((x.second.size() > q) || (x.second.size() == q && x.first < n)) {
            q = x.second.size();
            n = x.first;
        }
    }
    cout << n;
}

