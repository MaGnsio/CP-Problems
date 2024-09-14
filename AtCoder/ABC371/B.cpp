/**
 *    author:  MaGnsi0
 *    created: 14.09.2024 15:03:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<bool> done(n, false);
    while (m--) {
        int j; cin >> j; j--;
        char t; cin >> t;
        cout << (done[j] == false && t == 'M' ? "Yes" : "No") << "\n";
        done[j] = done[j] | (t == 'M');
    }
}
