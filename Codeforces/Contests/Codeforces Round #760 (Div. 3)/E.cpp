/**
 *    author:  MaGnsi0
 *    created: 14.12.2021 23:22:22
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
        vector<long long> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        long long X = accumulate(b.begin(), b.end(), 0LL);
        if (X % (n * (n + 1) / 2)) {
            cout << "NO\n";
            continue;
        }
        long long S = X / (n * (n + 1) / 2);
        bool ok = true;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = (S - b[i] + b[(i - 1 + n) % n]) / n;
            ok &= !(a[i] <= 0 || (S - b[i] + b[(i - 1 + n) % n]) % n);
        }
        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
    }
}
