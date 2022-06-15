/**
 *    author:  MaGnsi0
 *    created: 26.05.2022 16:18:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t l = 0, r = 1e9;
    while (l <= r) {
        int m = (l + r) / 2;
        cout << m << endl;
        char x;
        cin >> x;
        if (x == '=') {
            cout << "! " << m << endl;
            return 0;
        } else if (x == '<') {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
}
