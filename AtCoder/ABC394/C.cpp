/**
 *    author:  MaGnsi0
 *    created: 22.02.2025 14:03:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (s.substr(i, 2) == "WA") {
            s[i] = 'A', s[i + 1] = 'C';
            i = max(i - 3, -1);
        }
    }
    cout << s;
}
