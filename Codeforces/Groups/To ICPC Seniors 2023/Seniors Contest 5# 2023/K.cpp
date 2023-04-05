/**
 *    author:  MaGnsi0
 *    created: 08.02.2023 10:16:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    if (n != m) {
        cout << "No";
        return 0;
    }
    function<bool(char)> F = [&](char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    };
    for (int i = 0; i < n; ++i) {
        if (F(s[i]) != F(t[i])) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
