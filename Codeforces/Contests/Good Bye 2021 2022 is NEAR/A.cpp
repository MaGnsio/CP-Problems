/**
 *    author:  MaGnsi0
 *    created: 29.12.2021 17:20:52
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
        vector<int> f(105, 0);
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            x = abs(x);
            f[x]++;
            if (x == 0) {
                f[x] = min(f[x], 1);
            } else {
                f[x] = min(f[x], 2);
            }
        }
        cout << accumulate(f.begin(), f.end(), 0) << "\n";
    }
}
