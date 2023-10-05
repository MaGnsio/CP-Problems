/**
 *    author:  MaGnsi0
 *    created: 19.02.2022 18:42:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    long long l = 0, r = n * m, res;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long less = 0, lessequal = 0;
        for (int i = 1; i <= n; ++i) {
            long long x = mid / i - (mid % i == 0);
            x = min(x, m);
            less += x;
            lessequal += (x + (mid % i == 0 && mid / i <= m));
        }
        if (less < k && k <= lessequal) {
            res = mid;
            break;
        } else if (k <= less) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << res;
}
