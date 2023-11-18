/**
 *    author:  MaGnsi0
 *    created: 04.11.2023 17:46:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    bool ans = true;
    string t = "TRUTH";
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        if (s != t) {
            ans ^= 1;
        }
        s = t;
    }
    cout << (ans ? "TRUTH" : "LIE");
}
