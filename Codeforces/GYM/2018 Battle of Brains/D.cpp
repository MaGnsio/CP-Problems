/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 19:12:46
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s, x = "";
        cin >> s;
        for (int i = 0; i < s.size() - 1; ++i) {
            x += s[i];
        }
        reverse(x.begin(), x.end());
        s += x;
        cout << "Case " << t << ": " << s << "\n";
    }
}
