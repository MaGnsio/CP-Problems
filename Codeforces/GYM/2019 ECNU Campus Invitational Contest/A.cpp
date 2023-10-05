/**
 *    author:  MaGnsi0
 *    created: 09.09.2023 22:04:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int days = s.back() - '0';
    s.pop_back();
    if (s.size() == 2) {
        cout << days * (12 - s[0] + s[1]);
    } else if (s.size() == 3) {
        int L = stoi(s.substr(0, 2));
        int R = s.back() - '0';
        if (2 <= L && L <= 11 && 2 <= R && R <= 11) {
            cout << days * (12 - L + R);
        } else {
            L = s[0] - '0';
            R = stoi(s.substr(1, 2));
            cout << days * (12 - L + R);
        }
    } else {
        assert(s.size() == 4);
        int L = stoi(s.substr(0, 2));
        int R = stoi(s.substr(2, 2));
        cout << days * (12 - L + R);
    }
}
