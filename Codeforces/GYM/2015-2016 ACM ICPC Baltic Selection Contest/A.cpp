/**
 *    author:  MaGnsi0
 *    created: 26.12.2021 03:01:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b, c = "";
    cin >> a >> b;
    for (int i = 0; i < (int)a.size(); ++i) {
        c += char('0' + abs(a[i] - b[i]));
    }
    cout << stoll(c);
}
