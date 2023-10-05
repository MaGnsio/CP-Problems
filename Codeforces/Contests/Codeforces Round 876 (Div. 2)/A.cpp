/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 17:37:46
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
        int have = 0;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            if ((i + k) / k > have) {
                assert(have + 1 == (i + k) / k);
                a[i] = 1;
                have++;
            }
        }
        reverse(a.begin(), a.end());
        have = 0;
        for (int i = 0; i < n; ++i) {
            have += a[i];
            if ((i + k) / k > have) {
                assert(have + 1 == (i + k) / k);
                a[i] = 1;
                have++;
            }
        }
        int ans = count(a.begin(), a.end(), 1);
        cout << ans << "\n";
    }
}
