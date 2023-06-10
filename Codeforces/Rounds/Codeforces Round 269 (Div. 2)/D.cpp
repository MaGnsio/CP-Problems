/**
 *    author:  MaGnsi0
 *    created: 18.04.2023 05:24:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    if (m == 1) {
        cout << n;
        return 0;
    }
    vector<int> c(n + m - 1);
    for (int i = 0; i < n + m - 1; ++i) {
        if (i == m - 1) {
            c[i] = 2e9;
        } else {
            c[i] = (i < m - 1 ? b[i + 1] - b[i] : a[i - m + 1] - a[i - m]);
        }
    }
    vector<int> pi(n + m - 1);
    for (int i = 1; i < n + m - 1; ++i) {
        int j = pi[i - 1];
        while (j > 0 && c[i] != c[j]) {
            j = pi[j - 1];
        }
        pi[i] = j + (c[i] == c[j]);
    }
    int ans = 0;
    for (int i = 2 * m - 2; i < n + m - 1; ++i) {
        ans += pi[i] == m - 1;
    }
    cout << ans;
}
