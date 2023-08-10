/**
 *    author:  MaGnsi0
 *    created: 03.04.2023 22:04:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> f(26, 0);
    for (int i = 0; i < n; ++i) {
        f[s[i] - 'a']++;
    }
    int odds = 0;
    for (int i = 0; i < 26; ++i) {
        odds += f[i] % 2;
    }
    cout << max(1, odds);
}
