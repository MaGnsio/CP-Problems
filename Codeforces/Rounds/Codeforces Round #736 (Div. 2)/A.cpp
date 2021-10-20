/**
 *    author:  MaGnsi0
 *    created: 12/08/2021 18:53:49
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int p;
        cin >> p;
        if (p & 1) {
            cout << (p - 1) / 2 << " " << p - 1 << "\n";
        } else {
            cout << (p - 2) / 2 << " " << p - 2 << "\n";
        }
    }
}
