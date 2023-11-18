/**
 *    author:  MaGnsi0
 *    created: 23.10.2023 01:58:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int> F(26, 0);
    for (char c : s) {
        F[c - 'a']++;
    }
    for (int i = 0; i < 25; ++i) {
        F[i + 1] += F[i] / 2;
        F[i] -= 2 * (F[i] / 2);
    }
    for (int i = 25; i >= 0; --i) {
        for (int j = 0; j < F[i]; ++j) {
            cout << char('a' + i);
        }
    }
}
