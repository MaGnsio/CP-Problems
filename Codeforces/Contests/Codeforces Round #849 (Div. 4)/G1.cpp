/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:53:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] + i + 1;
        }
        sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] <= c) {
                c -= b[i];
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
