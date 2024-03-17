/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 14:00:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    bool good = 'A' <= s[0] && s[0] <= 'Z';
    for (int i = 1; i < (int)s.size(); ++i) {
        good = good && 'a' <= s[i] && s[i] <= 'z';
    }
    cout << (good ? "Yes" : "No");
}
