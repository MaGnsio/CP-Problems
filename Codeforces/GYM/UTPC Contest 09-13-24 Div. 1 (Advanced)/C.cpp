/**
 *    author:  MaGnsi0
 *    created: 27.11.2024 19:23:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int o = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            o += s[i] == '1';
            z += s[i] == '0';
        }
    }
    cout << min(o, z);
}
