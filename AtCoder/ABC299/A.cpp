/**
 *    author:  MaGnsi0
 *    created: 22.04.2023 14:00:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int x = -1, y, z;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '|') {
            if (x == -1) {
                x = i;
            } else {
                y = i;
            }
        }
        if (s[i] == '*') {
            z = i;
        }
    }
    cout << (x < z && z < y ? "in" : "out");
}
