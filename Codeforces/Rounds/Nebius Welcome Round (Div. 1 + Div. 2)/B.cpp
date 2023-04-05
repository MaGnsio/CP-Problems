/**
 *    author:  MaGnsi0
 *    created: 12.03.2023 16:41:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0, remaining_doses = 0, opening_time = 0;
        for (int i = 0; i < n; ++i) {
            if (remaining_doses == 0 || a[i] - opening_time > d) {
                remaining_doses = k;
                opening_time = a[i] + w;
                ans++;
            }
            remaining_doses--;
        }
        cout << ans << "\n";
    }
}
