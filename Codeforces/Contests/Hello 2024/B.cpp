/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 16:44:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int x = count(s.begin(), s.end(), '+');
        int y = n - x;
        cout << abs(y - x) << "\n";
    }
}
