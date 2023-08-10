/**
 *    author:  MaGnsi0
 *    created: 14.07.2023 15:21:53
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int ans = 1;
        for (int b = 0; b <= 30; ++b) {
            int val = 0;
            int64_t mask = ((1LL << 31) - 1) ^ ((1LL << (b + 1)) - 1);
            for (int i = 0; i < n; ++i) {
                val += ((a[i] >> b) & 1) && ((mask & a[i]) == 0);
            }
            ans = max(ans, val);
        }
        cout << ans << "\n";
    }
}
