/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 17:47:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << a[n - 1];
        for (int i = 0; i < n - 1; ++i) {
            cout << " " << a[i];
        }
        cout << "\n";
    }
}
