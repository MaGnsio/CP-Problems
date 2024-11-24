/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 22:14:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    if (n & 1) {
        cout << "No";
        return 0;
    }
    set<char> done;
    for (int i = 0; i < n; i += 2) {
        if (s[i] != s[i + 1] || done.count(s[i])) {
            cout << "No";
            return 0;
        }
        done.insert(s[i]);
    }
    cout << "Yes";
}
