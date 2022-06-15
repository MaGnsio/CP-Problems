/**
 *    author:  MaGnsi0
 *    created: 04.03.2022 07:06:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum < n) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        if (i + a[i] > n) {
            cout << -1;
            return 0;
        }
    }
    vector<int> res(m);
    for (int i = 0; i < m; ++i) {
        res[i] = i;
    }
    for (int i = m - 1, j = n - 1; i >= 0; --i) {
        if (res[i] + a[i] - 1 < j) {
            res[i] = j - a[i] + 1;
        }
        j = res[i] - 1;
    }
    for (int i = 0; i < m; ++i) {
        cout << res[i] + 1 << " ";
    }
}
