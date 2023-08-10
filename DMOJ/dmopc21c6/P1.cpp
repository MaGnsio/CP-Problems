/**
 *    author:  MaGnsi0
 *    created: 30.03.2023 22:01:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] < s[i + 1]) {
            swap(s[i], s[i + 1]);
            break;
        }
    }
    cout << s;
}
