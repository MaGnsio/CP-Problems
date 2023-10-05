/**
 *    author:  MaGnsi0
 *    created: 15.01.2023 14:23:27
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
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]]++;
        }
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            c[i] = b[i] + (i ? c[i - 1] : 0);
        }
        int ans = (c[0] == 0);
        for (int i = 0; i < n; ++i) {
            if (c[i] - (i ? c[i - 1] : 0) && c[i] - 1 >= i && c[min(c[i], n - 1)] - c[i] == 0) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
