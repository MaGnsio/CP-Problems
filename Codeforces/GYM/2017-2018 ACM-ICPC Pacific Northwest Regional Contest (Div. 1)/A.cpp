/**
 *    author:  MaGnsi0
 *    created: 08.11.2022 19:25:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    bool odd = true;
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        odd &= s[i] != s[i + 1]; 
    }
    cout << (odd ? "Odd." : "Or not.");
}
