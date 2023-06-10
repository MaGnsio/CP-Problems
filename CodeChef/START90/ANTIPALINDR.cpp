/**
 *    author:  MaGnsi0
 *    created: 17.05.2023 17:35:21
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
        string s;
        cin >> s;
        int odd = 0, even = 0;
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            odd += f[i] & 1;
            even += (f[i] != 0) && (f[i] % 2 == 0);
        }
        if (odd > 1) {
            cout << 0 << "\n";
        } else if (odd == 0) {
            cout << 1 << "\n";
        } else {
            if (even != 0) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
}
