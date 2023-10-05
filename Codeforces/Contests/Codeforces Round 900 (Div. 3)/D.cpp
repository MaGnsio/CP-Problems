/**
 *    author:  MaGnsi0
 *    created: 29.09.2023 17:10:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> L(k), R(k);
        for (int i = 0; i < k; ++i) {
            cin >> L[i]; L[i]--;
        }
        for (int i = 0; i < k; ++i) {
            cin >> R[i]; R[i]--;
        }
        vector<int> ans(n + 1);
        int Q;
        cin >> Q;
        while (Q--) {
            int x;
            cin >> x; x--;
            int j = upper_bound(L.begin(), L.end(), x) - L.begin() - 1;
            int low = min(x, L[j] + R[j] - x);
            int high = max(x, L[j] + R[j] - x);
            ans[low]++, ans[high + 1]--;
        }
        for (int i = 0; i < n; ++i) {
            ans[i + 1] += ans[i];
        }
        for (int i = 0; i < k; ++i) {
            int m = R[i] - L[i] + 1;
            for (int j = L[i], k = 0; k < m / 2 ; ++j, ++k) {
                assert(ans[j] == ans[R[i] - k]);
                if (ans[j] & 1) {
                    swap(s[j], s[R[i] - k]);
                }
            }
        }
        cout << s << "\n";
    }
}
