/**
 *    author:  MaGnsi0
 *    created: 25.07.2024 15:47:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, x; cin >> n >> x;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t ans = INT_MAX, sum = 0;
    for (int b = 31; b >= 0; --b) {
        int y = 0;
        for (int i = 0; i < n; ++i) {
            y += (a[i] >> b & 1);
        }
        if ((n % 2 == 0) && (y == n)) {
            if (x >> b & 1) {
                sum = INT_MAX;
                break;
            }
            continue;
        }
        if (x >> b & 1) {
            sum += (y % 2 == 0);
        } else {
            ans = min(ans, sum + (y % 2 == 0));
        }
    }
    ans = min(ans, sum);
    cout << (ans == INT_MAX ? -1 : ans);
}
