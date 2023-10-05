/**
 *    author:  MaGnsi0
 *    created: 29.11.2022 17:57:24
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        a.resize(unique(a.begin(), a.end()) - a.begin());
        n = (int)a.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (i == 0 || a[i - 1] > a[i]) && (i == n - 1 || a[i] < a[i + 1]);
        }
        cout << (cnt == 1 ? "YES" : "NO") << "\n";
    }
}
