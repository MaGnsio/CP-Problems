/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 01:00:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n;
    cin >> n;
    if (n == 0) {
        cout << 0 << " " << 1;
        return 0;
    }
    int64_t m = n, ans = 0;
    for (int64_t i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans++;
            if (i * i == n) {
                m = i;
            }
        }
    }
    cout << m << " " << (m == n ? ans : 2 * ans - 1);
}
