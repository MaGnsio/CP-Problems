/**
 *    author:  MaGnsi0
 *    created: 02.09.2024 22:32:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> F(2 * n + 2), ans(n + 1);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; F[x]++;
        }
        for (int i = 1; i <= 2 * n + 1; ++i) {
            F[i] += F[i - 1];
        }
        for (int x = 1; x <= n; ++x) {
            int low = 0, high = x - 1, median = x - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int count = 0;
                for (int i = 0; i <= n; i += x) {
                    count += F[i + mid] - (i ? F[i - 1] : 0);
                }
                if (count >= (n + 2) / 2) {
                    median = mid; high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans[x] = median;
        }
        while (Q--) {
            int x; cin >> x;
            cout << ans[x] << " ";
        }
        cout << "\n";
    }
}
