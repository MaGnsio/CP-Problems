/**
 *    author:  MaGnsi0
 *    created: 31/08/2021 01:49:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, o = 0, t = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        o += (x == 1);
        t += (x == 2);
    }
    cout << min(o, t) + (o - min(o, t)) / 3;
}
