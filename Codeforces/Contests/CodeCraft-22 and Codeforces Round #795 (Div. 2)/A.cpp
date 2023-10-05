/**
 *    author:  MaGnsi0
 *    created: 01.06.2022 15:39:03
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
        vector<int> a(2, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x % 2]++;
        }
        cout << min(a[0], a[1]) << "\n";
    }
}
