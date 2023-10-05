/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 17:46:38
**/
#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> R(n, OO), L(n, OO), v(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i < k; ++i) {
            int t;
            cin >> t;
            R[v[i] - 1] = L[v[i] - 1] = t;
        }
        for (int i = 1; i < n; ++i) {
            L[i] = min(L[i], L[i - 1] + 1);
        }
        for (int i = n - 2; i >= 0; --i) {
            R[i] = min(R[i], R[i + 1] + 1);
        }
        for (int i = 0; i < n; ++i) {
            cout << min(L[i], R[i]) << " ";
        }
        cout << "\n";
    }
}
