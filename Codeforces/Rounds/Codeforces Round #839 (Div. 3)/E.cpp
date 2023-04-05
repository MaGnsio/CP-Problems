/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 21:50:26
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
        int x = 0, y = 0, z = 0;
        for (int i = 1; i <= n; ++i) {
            x += a[i - 1] != i;
            y += a[i - 1] != n - i + 1;
            z += a[i - 1] != i && a[i - 1] != n - i + 1;
        }
        if (x == 0 && y == 0) {
            cout << "Tie\n";
        } else if (x <= y) {
            cout << (y - z < x ? "Tie" : "First") << "\n";
        } else {
            cout << (x - z <= y ? "Tie" : "Second") << "\n";
        }
    }
}
