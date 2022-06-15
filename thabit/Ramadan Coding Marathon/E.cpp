/**
 *    author:  MaGnsi0
 *    created: 07.04.2022 21:59:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long l = 0, r = 2e9, ans = -1;
    while (l <= r) {
        long long m = (l + r) / 2;
        long long cur = m;
        bool ok = true;
        for (int i = k - 1; i >= 0; --i) {
            if (a[i] <= cur) {
                cur--;
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}
