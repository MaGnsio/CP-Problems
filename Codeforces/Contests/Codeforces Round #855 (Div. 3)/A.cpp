/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 29:34:07
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
        for (auto& c : s) { c = tolower(c); }
        s.resize(unique(s.begin(), s.end()) - s.begin());
        cout << (s == "meow" ? "YES" : "NO") << "\n";
    }
}
