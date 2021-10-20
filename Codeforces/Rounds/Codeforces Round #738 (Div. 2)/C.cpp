/**
 *    author:  MaGnsi0
 *    created: 16/08/2021 19:26:04
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
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        if (n == 1) {
            if (v[0]) {
                cout << 2 << " " << 1;
            } else {
                cout << 1 << " " << 2;
            }
            cout << "\n";
            continue;
        }
        bool ok = false;
        for (int i = n - 1; i >= 0; --i) {
            if (!v[i]) {
                for (int j = 0; j <= i; ++j) {
                    cout << j + 1 << " ";
                }
                cout << n + 1 << " ";
                for (int j = i + 1; j < n; ++j) {
                    cout << j + 1 << " ";
                }
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << n + 1 << " ";
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }
}
