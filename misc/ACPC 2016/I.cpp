/**
 *    author:  MaGnsi0
 *    created: 01.07.2023 21:06:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t X, Y, Z, n;
        cin >> X >> Y >> Z >> n;
        if (n == 0) {
            int64_t nimber = (X - 1) ^ (Y - 1) ^ (Z - 1);
            cout << (nimber ? "Alice" : "Bob") << "\n";
            continue;
        }
        vector<int64_t> x(n), y(n), z(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i] >> z[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());
        int64_t nimber = 0;
        nimber ^= x[0] - 1;
        nimber ^= X - x[n - 1];
        nimber ^= y[0] - 1;
        nimber ^= Y - y[n - 1];
        nimber ^= z[0] - 1;
        nimber ^= Z - z[n - 1];
        cout << (nimber ? "Alice" : "Bob") << "\n";
    }
}
