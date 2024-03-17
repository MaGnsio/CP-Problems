/**
 *    author:  MaGnsi0
 *    created: 26.12.2023 16:41:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = -1;
        for (int64_t k = 2; /*-*/; k *= 2) {
            set<int64_t> s;
            for (int64_t x : a) {
                s.insert(x % k);
            }
            if (s.size() == 2) {
                ans = k;
                break;
            }
        }
        cout << ans << "\n";
    }
}
