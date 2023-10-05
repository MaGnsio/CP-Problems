/**
 *    author:  MaGnsi0
 *    created: 18/08/2021 16:27:50
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) {
            swap(a, b);
        }
        int k = 2 * (b - a);
        if (k < c || k < a || k < b) {
            cout << -1 << "\n";
        } else {
            cout << (c <= k / 2 ? c + k / 2 : c - k / 2) << "\n";
        }
    }
}
