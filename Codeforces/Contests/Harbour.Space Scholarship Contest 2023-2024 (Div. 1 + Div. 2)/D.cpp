/**
 *    author:  MaGnsi0
 *    created: 26.08.2023 18:27:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            vector<int> F(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                F[i] += L[i]; 
                F[i + 1] -= R[i];
            }
            for (int i = 1; i <= n; ++i) {
                F[i] += F[i - 1];
            }
            for (int j = 0; j < n; ++j) {
                if ((a[i][j] == '1') == (F[j] & 1)) {
                    continue;
                }
                L[j]++, R[j]++;
                ans++;
            }
            vector<int> new_L(n), new_R(n);
            new_L[0] = L[0], new_R[n - 1] = R[n - 1];
            for (int i = 0; i + 1 < n; ++i) {
                new_L[i] += L[i + 1]; 
            }
            for (int i = 1; i < n; ++i) {
                new_R[i] += R[i - 1];
            }
            swap(L, new_L);
            swap(R, new_R);
        }
        cout << ans << "\n";
    }
}
