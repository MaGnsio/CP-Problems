/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 22:17:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    vector<int64_t> F(10, 1), f(10);
    for (int64_t i = 1; i < 10; ++i) {
        F[i] = i * F[i - 1];
    }
    for (int i = 9; i; --i) {
        f[i] = (n / F[i]);
        n -= f[i] * F[i];
    }
    string ans = "";
    for (int i = 1; i < 10; ++i) {
        ans += string(f[i], char('0' + i));
    }
    cout << ans;
}
