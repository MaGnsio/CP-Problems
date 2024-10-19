/**
 *    author:  MaGnsi0
 *    created: 19.10.2024 17:10:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s(n, '0');
        s[n - 1] = '1';
        cout << s << "\n";
    }
}
