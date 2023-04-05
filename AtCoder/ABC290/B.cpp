/**
 *    author:  MaGnsi0
 *    created: 19.02.2023 14:03:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o' && k) {
            k--;
        } else {
            s[i] = 'x';
        }
    }
    cout << s;
}
