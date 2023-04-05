/**
 *    author:  MaGnsi0
 *    created: 13.03.2023 23:24:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; i += 2) {
        swap(s[i], s[i + 1]);
    }
    cout << s;
}
