/**
 *    author:  MaGnsi0
 *    created: 25.10.2021 17:28:52
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
        vector<long long> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        long long res = accumulate(a.begin(), a.end(), 0LL), mini = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            mini = min(mini, min(a[j], b[i]));
            res -= min(a[j], b[i]);
        }
        cout << res + mini << "\n";
    }
}
