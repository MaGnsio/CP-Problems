/**
 *    author:  MaGnsi0
 *    created: 29.09.2023 00:06:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size() / 2;
    int haveR = 0, haveL = 0;
    string ans(n, '*');
    for (int i = 0; i < n; ++i) {
        if (s[2 * i] == '<') {
            if (haveR == 0) {
                ans[i] = '[';
                haveL++;
            } else {
                ans[i] = ']';
                haveR--;
            }
        } else {
            if (haveL == 0) {
                ans[i] = '[';
                haveR++;
            } else {
                ans[i] = ']';
                haveL--;
            }
        }
    }
    if (haveL || haveR) {
        cout << "Keine Loesung";
    } else {
        cout << ans;
    }
}
