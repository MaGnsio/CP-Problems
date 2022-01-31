/**
 *    author:  MaGnsi0
 *    created: 20.01.2022 16:19:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << s << "\n";
    }
}
