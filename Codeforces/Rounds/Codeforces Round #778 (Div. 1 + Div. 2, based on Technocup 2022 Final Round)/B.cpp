/**
 *    author:  MaGnsi0
 *    created: 20.03.2022 13:30:15
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
        vector<int> f(26, 0);
        for (int i = 0; i < (int)s.size(); ++i) {
            f[s[i] - 'a']++;
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            if (f[s[i] - 'a'] > 1) {
                f[s[i] - 'a']--;
            } else {
                s = s.substr(i);
                break;
            }
        }
        cout << s << "\n";
    }
}
