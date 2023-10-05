/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 16:36:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long double> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<long double>());
        long double a = v[0], b = 0;
        for (int i = 1; i < n; ++i) {
            b += v[i];
        }
        long double res = a + (n > 1 ? b / double(n - 1) : 0.0);
        cout << fixed << setprecision(9) << res << "\n";
    }
}
