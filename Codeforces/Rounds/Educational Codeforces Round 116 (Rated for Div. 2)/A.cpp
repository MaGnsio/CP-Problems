/**
 *    author:  MaGnsi0
 *    created: 29.10.2021 16:29:07
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
        int a = (s[0] == 'a'), b = (s[0] == 'b');
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                a += (s[i] == 'a');
                b += (s[i] == 'b');
            }
        }
        s[0] = (a != b ? s[0] : (s[0] == 'a' ? 'b' : 'a'));
        cout << s << "\n";
    }
}
