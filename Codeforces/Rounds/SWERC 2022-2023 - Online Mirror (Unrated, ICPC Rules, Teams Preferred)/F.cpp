/**
 *    author:  TEAM
 *    created: 26.02.2023 17:36:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> U(m), V(m);
        for (int i = 0; i < m; ++i) {
            cin >> U[i] >> V[i];
            U[i]--, V[i]--;
            if (U[i] > V[i]) { swap(U[i], V[i]); }
        }
        vector<int> cnt(n, 0);
        for (int i = 0; i < m; ++i) {
            cnt[U[i]]++, cnt[V[i]]++;
        }
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] != n - 1) { v = i; }
        }
        if (v != -1) {
            vector<int> ans(m);
            for (int i = 0; i < m; ++i) {
                if (U[i] == v || V[i] == v) {
                    ans[i] = 1;
                } else {
                    ans[i] = 2;
                }
            }
            cout << 2 << "\n";
            for (int i = 0; i < m; ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        } else {
            vector<int> ans(m);
            for (int i = 0; i < m; ++i) {
                if (U[i] == 0) {
                    ans[i] = (V[i] % 2) + 1;
                } else {
                    ans[i] = 3;
                }
            }
            cout << 3 << "\n";
            for (int i = 0; i < m; ++i) {
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
    }
}
