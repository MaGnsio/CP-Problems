/**
 *    author:  MaGnsi0
 *    created: 10/09/2021 01:35:44
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int p, q;
    cin >> p >> q;
    if (p % 2 == 0) {
        cout << 0;
    } else if (q & 1) {
        cout << 1;
    } else {
        cout << (p < q ? 2 : 0);
    }
}
