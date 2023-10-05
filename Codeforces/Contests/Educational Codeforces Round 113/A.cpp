/**
 *    author:  MaGnsi0
 *    created: 08/09/2021 16:07:19
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] != s[i + 1]) {
                l = i + 1;
                r = i + 2;
            }
        }
        cout << l << " " << r << "\n";
    }
}
