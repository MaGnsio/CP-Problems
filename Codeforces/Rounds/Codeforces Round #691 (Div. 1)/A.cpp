/**
 *    author:  MaGnsi0
 *    created: 20.11.2021 18:33:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    long long g = 0;
    for (int i = 1; i < n; ++i) {
        g = __gcd(g, a[i] - a[0]);
    }
    for (int i = 0; i < m; ++i) {
        cout << __gcd(g, a[0] + b[i]) << " ";
    }
}
