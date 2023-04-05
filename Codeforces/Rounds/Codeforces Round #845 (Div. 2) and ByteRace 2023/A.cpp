/**
 *    author:  MaGnsi0
 *    created: 21.01.2023 16:35:58
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
            a[i] %= 2;
        }
        int ans = 0, cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] == a[i - 1]) {
                cnt++;
            } else {
                ans += cnt - 1;
                cnt = 1;
            }
        }
        ans += cnt - 1;
        cout << ans << "\n";
    }
}
