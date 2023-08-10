/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 17:37:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<string> a;
        for (int i = 0; i + 1 < n; ++i) {
            a.insert(s.substr(i, 2));
        }
        cout << (int)a.size() << "\n";
    }
}
