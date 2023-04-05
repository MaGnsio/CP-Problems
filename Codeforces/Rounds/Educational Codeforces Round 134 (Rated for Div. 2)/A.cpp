/**
 *    author:  MaGnsi0
 *    created: 20.03.2023 07:18:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        vector<string> s(2);
        cin >> s[0] >> s[1];
        set<char> s_;
        s_.insert(s[0][0]), s_.insert(s[0][1]);
        s_.insert(s[1][0]), s_.insert(s[1][1]);
        cout << (int)s_.size() - 1 << "\n";
    }
}
