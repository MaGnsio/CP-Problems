/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 01:22:24
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        cout << (count(t.begin(), t.end(), 'o') ? "YES\n" : "NO\n");
    }
}
