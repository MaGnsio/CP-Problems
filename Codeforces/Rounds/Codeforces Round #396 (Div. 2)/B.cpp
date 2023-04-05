/**
 *    author:  MaGnsi0
 *    created: 13.02.2023 10:12:56
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
    sort(a.begin(), a.end());
    bool ok = false;
    for (int i = 2; i < n; ++i) {
        ok |= a[i - 1] + a[i - 2] > a[i];
    }
    cout << (ok ? "YES" : "NO");
}
