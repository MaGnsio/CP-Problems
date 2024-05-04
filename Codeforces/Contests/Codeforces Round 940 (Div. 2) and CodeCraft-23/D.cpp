/**
 *    author:  MaGnsi0
 *    created: 26.04.2024 16:46:13
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 31;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t ans = 0;
        vector<vector<vector<int>>> c(B, vector<vector<int>>(2, vector<int>(2)));
        for (int i = 1, s = 0; i < n; ++i) {
            s ^= a[i];
            for (int b = 0; b < 30; ++b) {
                if (s >> b & 1) {
                    c[b][1][1]++;
                } else {
                    c[b][1][0]++;
                }
            }
        }
        for (int y = 0; y < n; ++y) {
            int msb = 0;
            for (int b = 0; b < B; ++b) {
                if (a[y] >> b & 1) {
                    msb = b;
                }
            }
            ans += c[msb][1][1];
            ans += c[msb][0][1];
            ans += 1LL * c[msb][0][0] * c[msb][1][1];
            ans += 1LL * c[msb][0][1] * c[msb][1][0];
            for (int b = 0; b < B; ++b) {
                if (a[y] >> b & 1) {
                    swap(c[b][0][0], c[b][0][1]);
                    c[b][0][1]++;
                } else {
                    c[b][0][0]++;
                }
                if (y + 1 == n) { continue; }
                if (a[y + 1] >> b & 1) {
                    c[b][1][1]--;
                    swap(c[b][1][0], c[b][1][1]);
                } else {
                    c[b][1][0]--;
                }
            }
        }
        cout << ans << "\n";
    }
}
