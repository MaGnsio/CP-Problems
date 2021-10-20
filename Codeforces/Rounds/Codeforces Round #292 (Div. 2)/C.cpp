/**
 *    author:  MaGnsi0
 *    created: 10/07/2021 04:07:01
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    string s = "";
    for (int i = 0; i < n; ++i) {
        char x;
        cin >> x;
        int a = x - '0';
        if (a == 4) {
            s += "223";
        } else if (a == 6) {
            s += "35";
        } else if (a == 8) {
            s += "2227";
        } else if (a == 9) {
            s += "2337";
        } else if (a > 1) {
            s += x;
        }
    }
    sort(s.begin(), s.end(), greater<char>());
    cout << s;
}
