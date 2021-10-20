/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:40
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    for (auto& c : s) {
        x += (c == '1');
        y += (c == '0');
    }
    if (x) {
        cout << '1';
    }
    for (int i = 0; i < y; ++i) {
        cout << '0';
    }
}
