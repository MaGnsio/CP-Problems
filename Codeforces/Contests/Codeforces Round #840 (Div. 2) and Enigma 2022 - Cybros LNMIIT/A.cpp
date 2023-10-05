/**
 *    author:  MaGnsi0
 *    created: 20.12.2022 20:42:50
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
        int maxe = 0, mine = (1 << 10) - 1;
        for (int i = 0; i < n; ++i) {
            maxe |= a[i];
            mine &= a[i];
        }
        cout << maxe - mine << "\n";
    }
}
