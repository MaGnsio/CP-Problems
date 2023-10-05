/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 17:07:02
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
        vector<int> a(n), b(n, 0);
        for (auto& x : a) {
            cin >> x;
        }
        b[0] = 0;
        for (int i = 1; i < n; ++i) {
            int x = a[i - 1] ^ b[i - 1];
            for (int j = 0; j < 30; ++j) {
                if (((1 << j) & x) && !((1 << j) & a[i])) {
                    b[i] |= (1 << j);
                }
            }
        }
        for (auto& x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
