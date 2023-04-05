/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 14:00:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (auto& c : s) {
        cout << (c == '1' ? '0' : '1');
    }
}
