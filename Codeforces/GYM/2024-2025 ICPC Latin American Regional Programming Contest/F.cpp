/**
 *    author:  MaGnsi0
 *    created: 16.11.2024 16:02:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; cin >> k;
    int n; cin >> n;
    string s(n, '-');
    for (int i = 1; i < n; i += 3) {
        s[i] = 'X'; k--;
    }
    if (n % 3 == 1) {
        s[n - 1] = 'X'; k--;
    }
    if (k < 0) {
        cout << "*\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (k == 0) { break; }
        if ((i - 2 < 0 || s[i - 2] == '-') && (i - 1 >= 0 && s[i - 1] == '-') && (s[i] == 'X') && (i + 1 < n && s[i + 1] == '-') && (i + 2 >= n || s[i + 2] == '-')) {
            s[i - 1] = 'X'; s[i] = '-'; s[i + 1] = 'X'; k--;
        }
    }
    if (k > 0) {
        cout << "*\n";
        return 0;
    }
    cout << s << "\n";
}
