/**
 *    author:  MaGnsi0
 *    created: 12/07/2021 04:48:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<long long> a(n), b(n), p(n);
    for (auto& x : a) {
        cin >> x;
    }
    for (auto& x : b) {
        cin >> x;
    }
    for (int i = 0; i < n; ++i) {
        p[i] = (i ? p[i - 1] : 0) + a[i] * b[i];
    }
    long long ans = p[n - 1];
    for (int i = 0; i < n; ++i) {
        long long rseg = a[i] * b[i];
        //segments with odd length with i in the center
        for (int l = i - 1, r = i + 1; l >= 0 && r < n; --l, ++r) {
            rseg += a[l] * b[r];
            rseg += a[r] * b[l];
            ans = max(ans, rseg + (l ? p[l - 1] : 0) + (p[n - 1] - p[r]));
        }
        //segments with even length with i & i+1 in the center
        rseg = 0;
        for (int l = i, r = i + 1; l >= 0 && r < n; --l, ++r) {
            rseg += a[l] * b[r];
            rseg += a[r] * b[l];
            ans = max(ans, rseg + (l ? p[l - 1] : 0) + (p[n - 1] - p[r]));
        }
    }
    cout << ans;
}
