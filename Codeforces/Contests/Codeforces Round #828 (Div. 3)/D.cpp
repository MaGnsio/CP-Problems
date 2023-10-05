/**
 *    author:  MaGnsi0
 *    created: 31.10.2022 19:17:55
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
            while (a[i] % 2 == 0) {
                b[i]++;
                a[i] /= 2;
            }
        }
        sort(b.begin(), b.end(), greater<int>());
        int ans = 0, sum = accumulate(b.begin(), b.end(), 0);
        vector<int> c(n);
        for (int i = 1; i <= n; ++i) {
            int x = i;
            while (x % 2 == 0) {
                c[i - 1]++;
                x /= 2;
            }
        }
        sort(c.begin(), c.end(), greater<int>());
        for (int i = 0; i < n; ++i) {
            if (sum >= n) {
                break;
            }
            sum += c[i];
            ans++;
        }
        cout << (sum >= n ? ans : -1) << "\n";
    }
}
