/**
 *    author:  MaGnsi0
 *    created: 22.02.2025 13:58:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    string s; cin >> s;
    string ans(count(s.begin(), s.end(), '2'), '2');
    cout << ans;
}
