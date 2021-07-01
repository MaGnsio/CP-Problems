//https://www.e-olymp.com/en/contests/15927/problems/164113
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, Q;
    cin >> N;
    vector<vector<int>> V(N + 1);
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y;
            cin >> x >> y;
            V[x].push_back(y);
            V[y].push_back(x);
        } else {
            int u;
            cin >> u;
            for (int i = 0; i < V[u].size(); ++i) {
                cout << V[u][i] << " ";
            }
            cout << "\n";
        }
    }
}

