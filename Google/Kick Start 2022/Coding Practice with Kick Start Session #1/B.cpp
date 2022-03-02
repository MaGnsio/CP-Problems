/**
 *    author:  MaGnsi0
 *    created: 15.02.2022 00:31:30
**/
#include <bits/stdc++.h>

using namespace std;

string get_ruler(string s) {
    set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    if (s.back() == 'y' || s.back() == 'Y') {
        return "nobody.";
    } else if (vowels.count(s.back())) {
        return "Alice.";
    } else {
        return "Bob.";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        cout << "Case #" << t << ": "
             << s << " is ruled by " << get_ruler(s) << "\n";
    }
}
