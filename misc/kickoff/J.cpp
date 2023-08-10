/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 18:18:26
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
    vector<int> b(n);
    for (int i = 0; i + 1 < n; ++i) {
        b[i] = abs(a[i + 1] - a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        b[i] = max(b[i], b[i + 1]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x, k;
        cin >> x >> k;
        int j = lower_bound(a.begin(), a.end(), x) - a.begin();
        cout << (b[j] <= k ? "YES" : "NO") << "\n";
    }
}
