/**
 *    author:  MaGnsi0
 *    created: 19.04.2022 16:28:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << (a[0] + 1 <= m ? "YES" : "NO") << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        int64_t S = accumulate(a.begin(), a.end(), (int64_t)0);
        cout << (S - a[0] + a[n - 1] + n <= m ? "YES" : "NO") << "\n";
    }
}
