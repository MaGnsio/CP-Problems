/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 00:25:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << "Case #" << t << ": ";
        cout << accumulate(a.begin(), a.end(), 0) % m << "\n";
    }
}
