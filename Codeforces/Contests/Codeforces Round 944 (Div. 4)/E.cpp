/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        int Q; cin >> Q;
        vector<int64_t> a(k + 1), b(k + 1); 
        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> b[i];
        }
        while (Q--) {
            int d; cin >> d;
            int low = 0, high = k, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid] <= d) {
                    j = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if (d == a[j]) {
                cout << b[j] << " ";
                continue;
            }
            int ans = b[j] + (d - a[j]) * (b[j + 1] - b[j]) / (a[j + 1] - a[j]);
            cout << ans << " ";
        }
        cout << "\n";
    }
}
