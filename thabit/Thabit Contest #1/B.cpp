/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 16:37:57
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string a, b;
    cin >> a >> b;
    if ((a.size() + b.size()) & 1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (i + b.size() - j != j + a.size() - i) {
                continue;
            }
            string x = b.substr(0, b.size() - j) + a.substr(0, i);
            string y = b.substr(b.size() - j, j) + a.substr(i, a.size() - i);
            if (x == y) {
                cout << x;
                return 0;
            }
        }
    }
    cout << -1;
}
