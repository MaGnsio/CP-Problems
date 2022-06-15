/**
 *    author:  MaGnsi0
 *    created: 09.03.2022 16:33:53
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        long long maxi = 0, mini = LLONG_MAX, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                sum -= a[i];
                maxi = max(maxi, a[i]);
            } else {
                sum += a[i];
                mini = min(mini, a[i]);
            }
        }
        cout << max(sum, sum + 2 * maxi - 2 * mini) << "\n";
    }
}
