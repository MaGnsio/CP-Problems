/**
 *    author:  MaGnsi0
 *    created: 06.11.2022 16:36:50
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
        cout << (a[0] == 1 ? "YES" : "NO") << "\n";
    }
}
