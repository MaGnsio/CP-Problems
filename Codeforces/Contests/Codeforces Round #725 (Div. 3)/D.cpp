/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:23:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, k, cnt1 = 0, cnt2 = 0;
        cin >> a >> b >> k;
        int ta = a, tb = b;
        for (int i = 2; i * i <= ta; ++i) {
            while (ta % i == 0) {
                ta /= i;
                cnt1++;
            }
        }
        if (ta > 1) {
            cnt1++;
        }
        for (int i = 2; i * i <= tb; ++i) {
            while (tb % i == 0) {
                tb /= i;
                cnt1++;
            }
        }
        if (tb > 1) {
            cnt1++;
        }
        ta = a / gcd(a, b), tb = b / gcd(a, b);
        for (int i = 2; i * i <= ta; ++i) {
            while (ta % i == 0) {
                ta /= i;
                cnt2++;
            }
        }
        if (ta > 1) {
            cnt2++;
        }
        for (int i = 2; i * i <= tb; ++i) {
            while (tb % i == 0) {
                tb /= i;
                cnt2++;
            }
        }
        if (tb > 1) {
            cnt2++;
        }
        if ((k > 1 && cnt1 >= k) || (k == 1 && (a / gcd(a, b) == 1 ^ b / gcd(a, b) == 1))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
