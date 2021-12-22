/**
 *    author:  MaGnsi0
 *    created: 11.11.2021 17:38:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int res = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        int j = i;
        while (j < (int)s.size() && s[j] == s[i]) {
            j++;
        }
        res = max(res, j - i);
        i = j - 1;
    }
    cout << res;
}
