/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 15:20:59
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
            cout << "? " << i + 1 << " " << (i + 1) % n + 1   << " " << (i + 2) % n + 1 << endl;
            cin >> a[i];
        }
        int x, y;
        for (int i = 0; i < n; ++i) {
            if (a[i] != a[(i + 1) % n]) {
                if (a[i] == 1) {
                    x = i;
                    y = (i + 3) % n;
                } else {
                    x = (i + 3) % n;
                    y = i;
                }
            }
        }
        vector<int> res(n, 1);
        res[y] = 0;
        for (int i = 0; i < n; ++i) {
            if (i == x || i == y) {
                continue;
            }
            cout << "? " << i + 1 << " " << x + 1 << " " << y + 1 << endl;
            cin >> res[i]; 
        }
        cout << "! " << count(res.begin(), res.end(), 0) << " ";
        for (int i = 0; i < n; ++i) {
            if (!res[i]) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}
