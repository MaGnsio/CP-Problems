/**
 *    author:  MaGnsi0
 *    created: 08.01.2023 16:36:48
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
        if (a[0] == a[n - 1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << a[0];
            for (int i = n - 1; i > 0; --i) {
                cout << " " << a[i];
            }
            cout << "\n";
        }
    }
}
