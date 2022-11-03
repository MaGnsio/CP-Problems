/**
 *    author:  MaGnsi0
 *    created: 16.06.2022 16:35:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        while (a && b) {
            cout << "01";
            a--, b--;
        }
        while (a) {
            cout << "0";
            a--;
        }
        while (b) {
            cout << "1";
            b--;
        }
        cout << "\n";
    }
}
