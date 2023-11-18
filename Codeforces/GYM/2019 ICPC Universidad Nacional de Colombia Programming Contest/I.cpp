/**
 *    author:  MaGnsi0
 *    created: 02.11.2023 11:09:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    string ans = "";
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            ans += c;
        } else {
            break;
        }
    }
    cout << (ans.empty() ? "-1" : ans);
}
