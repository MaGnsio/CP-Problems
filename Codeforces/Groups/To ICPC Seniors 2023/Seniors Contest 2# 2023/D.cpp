/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 09:05:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i <= n / 2; ++i) {
        if (s[i] != '?' && s[n - i - 1] != '?') {
            if (s[i] != s[n - i - 1]) {
                cout << -1;
                return 0;
            }
        } else if (s[i] == '?' && s[n - i - 1] == '?') {
            s[i] = s[n - i - 1] = 'a';
        } else if (s[i] == '?') {
            s[i] = s[n - i - 1];
        } else {
            s[n - i - 1] = s[i];
        }
    }
    cout << s;
}
