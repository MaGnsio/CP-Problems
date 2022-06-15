/**
 *    author:  MaGnsi0
 *    created: 02.05.2022 20:56:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        int x = count(t.begin(), t.end(), 'a');
        cout << (x ? ((int)t.size() == 1 ? 1LL : -1LL) : 1LL << (int)s.size()) << "\n";
    }
}
