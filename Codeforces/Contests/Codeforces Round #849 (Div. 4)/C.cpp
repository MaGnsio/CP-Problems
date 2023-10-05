/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:14:18
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
        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                break;
            }
            l++, r--;
        }
        cout << r - l + 1 << "\n";
    }
}
