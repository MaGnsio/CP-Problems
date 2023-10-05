/**
 *    author:  MaGnsi0
 *    created: 19.11.2022 01:15:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        vector<int> s = {2, 2, 3};
        do {
            int j = 0, cnt = 0;
            int64_t p = h;
            for (int i = 0; i < n; ++i) {
                while (j < 3 && p <= a[i]) {
                    p *= s[j++];
                }
                if (p > a[i]) {
                    p += a[i] / 2;
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        } while (next_permutation(s.begin(), s.end()));
        cout << ans << "\n";
    }
}
