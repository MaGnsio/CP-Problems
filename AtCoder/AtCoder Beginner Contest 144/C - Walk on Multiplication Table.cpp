/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 14:31:36
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, ans = LLONG_MAX;
    cin >> n;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans = min(ans, i + (n / i) - 2);
        }
    }
    cout << ans;
}
