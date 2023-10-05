/**
 *    author:  MaGnsi0
 *    created: 13.05.2022 16:34:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int l = max(l1, l2), r = min(r1, r2);
        cout << (l <= r ? l : l1 + l2) << "\n";
    }
}
