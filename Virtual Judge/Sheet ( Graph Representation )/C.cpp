//https://vjudge.net/contest/372876#problem/C
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    while (cin >> N >> M) {
        vector<vector<int>> V(1000001);
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            V[x].push_back(i + 1);
        }
        for (int i = 0; i < M; ++i) {
            int k, u;
            cin >> k >> u;
            cout << (V[u].size() < k ? 0 : V[u][k - 1]) << "\n";
        }
    }
}

