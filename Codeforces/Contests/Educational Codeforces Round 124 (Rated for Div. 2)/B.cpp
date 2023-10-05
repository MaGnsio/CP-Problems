/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 16:30:27
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
        bool ok = true;
        vector<long long> a(n, 1);
        for (int i = 1; i < n; ++i) {
            a[i] = 3 * a[i - 1];
            if (a[i] > (long long)1e9) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
