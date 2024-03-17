/**
 *    author:  MaGnsi0
 *    created: 27.01.2024 14:02:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int> f(26);
    for (char c : s) {
        f[c - 'a']++;
    }
    int maxf = *max_element(f.begin(), f.end());
    for (int i = 0; i < 26; ++i) {
        if (f[i] == maxf) {
            cout << char('a' + i);
            return 0;
        }
    }
}
