/**
 *    author:  MaGnsi0
 *    created: 10.07.2022 16:32:27
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
        int ans = 0;
        set<char> to_memorize;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (!to_memorize.count(s[i]) && (int)to_memorize.size() == 3) {
                ans++;
                to_memorize.clear();
                to_memorize.insert(s[i]);
            } else {
                to_memorize.insert(s[i]);
            }
        }
        cout << ans + !to_memorize.empty() << "\n";
    }
}
