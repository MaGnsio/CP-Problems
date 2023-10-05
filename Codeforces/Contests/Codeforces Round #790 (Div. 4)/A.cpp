/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
            sum += (s[i] - '0');
        }
        for (int i = 3; i < 6; ++i) {
            sum -= (s[i] - '0');
        }
        cout << (sum ? "NO" : "YES") << "\n";
    }
}
