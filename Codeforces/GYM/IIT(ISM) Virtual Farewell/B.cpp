/**
 *    author:  MaGnsi0
 *    created: 26.12.2021 20:55:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    string a = "", b = "";
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] & 1) {
            a += s[i];
        } else {
            b += s[i];
        }
    }
    string c = "", d = "";
    for (int i = 0; i < (int)t.size(); ++i) {
        if (t[i] & 1) {
            c += t[i];
        } else {
            d += t[i];
        }
    }
    cout << (a == c && b == d ? "Yes" : "No");
}
