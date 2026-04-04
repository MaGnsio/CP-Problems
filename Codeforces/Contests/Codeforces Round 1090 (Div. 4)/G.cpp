/**
 *    author:  MaGnsi0
 *    created: 04.04.2026 17:26:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 676767677;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        int64_t ans = 1;
        vector<set<int>> T(m);
        vector<int> B(n), L(n), R(n), A(n, m + 1), S(n, -1);
        for (int i = 0; i < n; ++i) {
            cin >> B[i]; T[B[i]].insert(i);
            if (B[i] == 0) { S[i] = 0; }
        }
        int total_done = 0, last_done = 0;
        for (int t = 0; t < m; ++t) {
            set<int> ready = T[t];
            for (int x : ready) {
                if (S[x] != 0) { ans = 0; }
                if (B[x] == 0) {
                    L[x] = 0; R[x] = 0;
                } else if (A[x] < t) {
                    L[x] = total_done - last_done + 1; R[x] = total_done;
                } else {
                    L[x] = 1; R[x] = total_done;
                }
                S[x] = 1;
            }
            for (int x : ready) {
                if (x - 1 >= 0 && S[x - 1] == -1) {
                    A[x - 1] = B[x] + 1; S[x - 1] = 0;
                }
                if (x + 1 < n && S[x + 1] == -1) {
                    A[x + 1] = B[x] + 1; S[x + 1] = 0;
                }
            }
            total_done += (int)ready.size();
            last_done = (int)ready.size();
        }
        for (int i = 0; i < n; ++i) {
            ans *= int64_t(R[i] - L[i] + 1);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
