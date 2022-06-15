/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:10:49
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        x += (s[i] == 'R');
        x -= (s[i] == 'L');
        y += (s[i] == 'U');
        y -= (s[i] == 'D');
    }
    cout << x << " " << y;
}
