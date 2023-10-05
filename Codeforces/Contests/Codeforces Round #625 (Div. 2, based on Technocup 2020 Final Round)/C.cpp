/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 23:58:21
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, maxi = 0;
    string s;
    cin >> n >> s;
    for (char c = 'z'; c > 'a'; --c) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != c) {
                continue;
            }
            if ((i && s[i - 1] == char(c - 1)) || (i + 1 < s.size() && s[i + 1] == char(c - 1))) {
                s.erase(i, 1);
                i = -1;
                maxi++;
            }
        }
    }
    cout << maxi;
}
