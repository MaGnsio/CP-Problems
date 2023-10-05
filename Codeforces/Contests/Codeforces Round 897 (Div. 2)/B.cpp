/**
 *    author:  MaGnsi0
 *    created: 11.09.2023 17:42:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int x = 0, y, z = n & 1;
        for (int i = 0; i < n / 2; ++i) {
            x += s[i] != s[n - i - 1];
        }
        y = (n - 2 * x - z) / 2;
        string t(n + 1, '0');
        for (int i = x; i <= n; ++i) {
            int rem = i - x;
            if (rem % 2 == 0 && rem / 2 <= y) {
                t[i] = '1';
            } else if (rem % 2 == 1 && z && (rem - 1) / 2 <= y) {
                t[i] = '1';
            }
        }
        cout << t << "\n";
    }
}
