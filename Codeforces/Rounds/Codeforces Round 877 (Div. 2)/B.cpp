/**
 *    author:  MaGnsi0
 *    created: 04.06.2023 17:51:28
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int pos1, pos2, posn;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) { pos1 = i; }
            if (a[i] == 2) { pos2 = i; }
            if (a[i] == n) { posn = i; }
        }
        if (pos1 > pos2) { swap(pos1, pos2); }
        if (pos1 < posn && posn < pos2) {
            cout << 1 << " " << 1 << "\n";
        } else if (posn < pos1) {
            cout << posn + 1 << " " << pos1 + 1 << "\n";
        } else {
            cout << pos2 + 1 << " " << posn + 1 << "\n";
        }
    }
}
