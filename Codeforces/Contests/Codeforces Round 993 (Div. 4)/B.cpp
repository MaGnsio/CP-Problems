/**
 *    author:  MaGnsi0
 *    created: 15.12.2024 17:36:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        for (char& c : s) {
            c = (c == 'w' ? 'w' : (c == 'p' ? 'q' : 'p'));
        }
        cout << s << "\n";
    }
}
