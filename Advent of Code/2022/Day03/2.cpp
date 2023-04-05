/**
 *    author:  MaGnsi0
 *    created: 13.12.2022 14:37:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    int64_t ans = 0;
    string a, b, c;
    while (getline(cin, a) && getline(cin, b) && getline(cin, c)) {
        set<char> x(a.begin(), a.end());
        set<char> y(b.begin(), b.end());
        set<char> z(c.begin(), c.end());
        for (char j = 'Z'; j >= 'A'; --j) {
            if (x.count(j) && y.count(j) && z.count(j)) {
                ans += j - 'A' + 27;
                goto done;
            }
        }
        for (char j = 'z'; j >= 'a'; --j) {
            if (x.count(j) && y.count(j) && z.count(j)) {
                ans += j - 'a' + 1;
                goto done;
            }
        }
        done:;
    }
    cout << ans;
}
