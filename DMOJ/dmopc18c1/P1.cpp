/**
 *    author:  MaGnsi0
 *    created: 27.03.2023 22:24:51
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
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (a[i]) { b.push_back(a[i]); }
    }
    if (!is_sorted(b.begin(), b.end())) {
        cout << "NO";
        return 0;
    }
    int L = 1, R = 1e9, j = 0;
    while (j < n) {
        if (a[j]) { j++; continue; }
        int l = (j ? a[j - 1] : 1);
        while (a[j] == 0 && j < n) { j++; }
        int r = (j < n ? a[j] : 1e9);
        if (R < l || r < L) {
            cout << "NO";
            return 0;
        }
        L = max(L, l);
        R = min(R, r);
    }
    cout << "YES";
}
