/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> mod(k, 0);
        for (int i = 0; i < n; ++i) {
            mod[a[i] % k]++;
            a[i] -= (a[i] % k);
        }
        int64_t ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (int64_t)a[i] / k;
        }
        for (int i = 1; i < k; ++i) {
            for (int j = k - i; j < k; ++j) {
                if (mod[i] == 0) {
                    break;
                }
                if (j == i) {
                    int x = mod[i] / 2;
                    ans += x;
                    mod[i] -= 2 * x;
                } else if (mod[j] <= mod[i]) {
                    ans += mod[j];
                    mod[i] -= mod[j];
                    mod[j] = 0;
                } else {
                    ans += mod[i];
                    mod[j] -= mod[i];
                    mod[i] = 0;
                }
            }
        }
        cout << ans << "\n";
    }
}
