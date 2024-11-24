/**
 *    author:  MaGnsi0
 *    created: 24.11.2024 21:38:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 0) {
        cout << "No";
        return 0;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != '1') {
            cout << "No";
            return 0;
        }
    }
    if (s[n / 2] != '/') {
        cout << "No";
        return 0;
    }
    for (int i = (n / 2) + 1; i < n; ++i) {
        if (s[i] != '2') {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
