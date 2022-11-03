/**
 *    author:  MaGnsi0
 *    created: 21.07.2022 16:34:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        vector<int> a(3);
        for (int i = 0; i < 3; ++i) {
            cin >> a[i];
        }
        if (a[x - 1] == 0) {
            cout << "NO\n";
        } else {
            x = a[x - 1];
            if (a[x - 1] == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}
