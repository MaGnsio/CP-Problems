/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:43:35
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
        sort(a.begin(), a.end());
        int ans = 1, cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] > k) {
                ans = max(ans, cnt);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        ans = n - ans;
        cout << ans << "\n";
    }
}
