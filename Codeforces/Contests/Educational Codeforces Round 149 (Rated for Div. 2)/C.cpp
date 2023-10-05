/**
 *    author:  MaGnsi0
 *    created: 25.05.2023 17:56:36
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
        char last = '0';
        for (char& c : s) {
            if (c == '?') {
                c = last;
            } else {
                last = c;
            }
        }
        cout << s << "\n";
    }
}
