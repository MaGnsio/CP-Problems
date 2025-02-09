/**
 *    author:  MaGnsi0
 *    created: 09.02.2025 16:35:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        s.pop_back(); s.pop_back(); s += "i";
        cout << s << "\n";
    }
}
