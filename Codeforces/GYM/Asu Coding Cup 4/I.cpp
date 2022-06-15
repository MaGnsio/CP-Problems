/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:25:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    for (int i = 0; i < n; ++i) {
        a += s[i] == 'a';
        b += s[i] == 'b';
        c += s[i] == 'c';
        d += s[i] == 'd';
        e += s[i] == 'e';
    }
    cout << min({a, b, c, d, e}) << " " << max({a, b, c, d, e});
}
