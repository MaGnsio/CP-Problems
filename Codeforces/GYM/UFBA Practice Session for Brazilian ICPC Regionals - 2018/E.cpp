/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 00:17:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    if (n == 1) {
        cout << (s[0] == '0' ? "YES" : "NO");
        return 0;
    }
    int Xor = 0;
    for (int i = 0; i < n; ++i) {
        Xor = Xor ^ (s[i] - '0');
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        ans = ans && ((Xor ^ (s[i] - '0')) == (s[i] - '0'));
    }
    cout << (ans ? "YES" : "NO");
}
