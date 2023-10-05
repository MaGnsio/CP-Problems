/**
 *    author:  MaGnsi0
 *    created: 14.06.2023 02:44:58
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
        int m = 0, y = -1, first = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x >= y) {
                if (m) {
                    if (x <= first) {
                        y = x;
                        cout << 1;
                    } else {
                        cout << 0;
                    }
                } else {
                    y = x;
                    cout << 1;
                }
            } else if (m == 0 && x <= first) {
                y = x;
                m++;
                cout << 1;
            } else {
                cout << 0;
            }
            if (first == -1) {
                first = x;
            }
        }
        cout << "\n";
    }
}
