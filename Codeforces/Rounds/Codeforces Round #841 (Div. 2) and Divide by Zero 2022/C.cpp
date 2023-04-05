/**
 *    author:  MaGnsi0
 *    created: 27.12.2022 17:25:09
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

vector<int> mp(N, 0);


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
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m |= a[i];
        }
        int64_t ans = int64_t(n) * (n + 1) / 2;
        for (int64_t i = 0; i * i <= m; ++i) {
            int64_t cur_xor = 0, x = i * i;
            mp[0] = 1;
            for (int j = 0; j < n; ++j) {
                cur_xor ^= a[j];
                ans -= mp[cur_xor ^ x]; 
                mp[cur_xor]++;
            }
            cur_xor = 0;
            for (int j = 0; j < n; ++j) {
                cur_xor ^= a[j];
                mp[cur_xor]--;
            }
            mp[0] = 0;
        }
        cout << ans << "\n";
    }
}
