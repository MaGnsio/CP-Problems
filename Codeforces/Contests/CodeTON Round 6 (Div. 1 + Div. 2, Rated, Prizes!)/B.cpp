/**
 *    author:  MaGnsi0
 *    created: 18.09.2023 17:39:50
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t or_sum = 0;
        for (int i = 0; i < m; ++i) {
            int x; cin >> x; or_sum |= x;
        }
        int64_t max_ans = 0, min_ans = 0;
        if (n & 1) {
            for (int i = 0; i < n; ++i) {
                max_ans ^= (a[i] | or_sum);
                min_ans ^= a[i];
            }
        } else {
            for (int i = 0; i < n; ++i) {
                max_ans ^= a[i];
                min_ans ^= (a[i] | or_sum);
            }
        }
        cout << min_ans << " " << max_ans << "\n";
    }
}
