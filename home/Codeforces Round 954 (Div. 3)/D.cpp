/**
 *    author:  MaGnsi0
 *    created: 23.06.2024 18:08:07
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        if (n == 2) {
            cout << stoi(s) << "\n";
            continue;
        }
        int ans = OO;
        for (int skip = 0; skip + 1 < n; ++skip) {
            vector<int> a;
            for (int i = 0; i < n; ++i) {
                if (skip == i) {
                    a.push_back(stoi(s.substr(i++, 2)));
                } else {
                    a.push_back(s[i] - '0');
                }
            }
            if (count(a.begin(), a.end(), 0)) {
                ans = 0;
                break;
            }
            ans = min(ans, max(accumulate(a.begin(), a.end(), 0) - (int)count(a.begin(), a.end(), 1), 1));
        }
        cout << ans << "\n";
    }
}
