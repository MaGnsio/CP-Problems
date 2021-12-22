/**
 *    author:  MaGnsi0
 *    created: 25.10.2021 23:31:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pre(n), suf(n);
    pre[0] = a[0], suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; ++i) {
        pre[i] = gcd(pre[i - 1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = gcd(suf[i + 1], a[i]);
    }
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        int g = gcd((i ? pre[i - 1] : 0), (i + 1 < n ? suf[i + 1] : 0)); 
        res = (long long)g * res / gcd(g, res);
    }
    cout << res;
}
