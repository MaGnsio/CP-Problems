/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 03:21:27
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cur = 0;
        string s = "abcdefghijklmnopqrstuvwxyz";
        while (n) {
            int x;
            for (x = 1; (x + 1) * (x + 2) / 2 <= n; ++x) {
            }
            n -= x * (x + 1) / 2;
            for (int i = 0; i < x; ++i) {
                cout << s[cur];
            }
            cur = (cur + 1) % 26;
        }
        cout << "\n";
    }
}
