/**
 *    author:  MaGnsi0
 *    created: 25.05.2024 15:07:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int T; cin >> T;
    int nDF = n, nDR = n;
    vector<int> I(n * n, -1), J(n * n, -1);
    vector<int> countR(n, n), countC(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = n * i + j;
            I[x] = i, J[x] = j;
        }
    }
    int ans = T + 1;
    for (int t = 1; t <= T; ++t) {
        int x; cin >> x; x--;
        countR[I[x]]--;
        if (countR[I[x]] == 0) { ans = min(ans, t); }
        countC[J[x]]--;
        if (countC[J[x]] == 0) { ans = min(ans, t); }
        if (I[x] == J[x]) { nDF--; }
        if (nDF == 0) { ans = min(ans, t); }
        if (I[x] + J[x] == n - 1) { nDR--; }
        if (nDR == 0) { ans = min(ans, t); }
    }
    cout << (ans == T + 1 ? -1 : ans);
}
