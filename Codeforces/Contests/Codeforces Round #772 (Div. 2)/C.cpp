/**
 *    author:  MaGnsi0
 *    created: 20.02.2022 16:26:27
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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[n - 2] > a[n - 1]) {
            cout << "-1\n";
        } else {
            if (!(a[n - 2] < 0 && a[n - 1] < 0)) {
                cout << n - 2 << "\n";
                for (int i = 0; i < n - 2; ++i) {
                    cout << i + 1 << " " << n - 1 << " " << n << "\n";
                }
            } else {
                bool good = true;
                for (int i = 1; i < n; ++i) {
                    if (a[i] < a[i - 1]) {
                        good = false;
                        break;
                    }
                }
                cout << (good ? 0 : -1) << "\n";
            }
        }
    }
}
