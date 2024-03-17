/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 16:48:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b, c;
        b.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (a[i] <= b.back() && !c.empty() && a[i] <= c.back()) {
                if (b.back() <= c.back()) {
                    b.push_back(a[i]);
                } else {
                    c.push_back(a[i]);
                }
            } else if (a[i] <= b.back()) {
                b.push_back(a[i]);
            } else if (c.empty() || a[i] <= c.back()) {
                c.push_back(a[i]);
            } else if (b.back() <= c.back()) {
                b.push_back(a[i]);
            } else {
                c.push_back(a[i]);
            }
        }
        int ans = 0;
        for (int i = 1; i < (int)b.size(); ++i) {
            ans += b[i] > b[i - 1];
        }
        for (int i = 1; i < (int)c.size(); ++i) {
            ans += c[i] > c[i - 1];
        }
        cout << ans << "\n";
    }
}
