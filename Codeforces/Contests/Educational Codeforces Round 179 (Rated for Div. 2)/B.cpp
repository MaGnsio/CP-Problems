/**
 *    author:  MaGnsi0
 *    created: 06.06.2025 21:16:13
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> F(N);
    F[0] = 1, F[1] = 2;
    for (int i = 2; i < N; ++i) {
        F[i] = F[i - 1] + F[i - 2];
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int lt = F[n - 1], ht = F[n - 1] + F[n - 2];
        for (int i = 0; i < m; ++i) {
            vector<int> D(3);
            for (auto& d : D) { cin >> d; }
            sort(D.begin(), D.end());
            bool ok = false;
            do {
                ok |= (D[0] >= lt && D[1] >= lt && D[2] >= ht);
            } while (next_permutation(D.begin(), D.end()));
            cout << (ok ? 1 : 0) << (i == m - 1 ? "\n" : "");
        }
    }
}
