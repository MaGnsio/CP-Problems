/**
 *    author:  MaGnsi0
 *    created: 26.09.2023 21:51:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
    if (sum % 3) { return cout << 0, 0; }
    vector<int64_t> p = a, s = a;
    for (int i = 1; i < n; ++i) {
        p[i] += p[i - 1];
        s[n - i - 1] += s[n - i];
    }
    vector<int64_t> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = s[i] == sum / 3;
    }
    for (int i = n - 2; i >= 0; --i) {
        b[i] += b[i + 1];
    }
    int64_t ans = 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (p[i] == sum / 3) {
            ans += b[i + 2];
        }
    }
    cout << ans;
}
