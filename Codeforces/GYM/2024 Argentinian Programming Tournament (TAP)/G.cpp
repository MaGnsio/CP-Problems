/**
 *    author:  MaGnsi0
 *    created: 08.09.2024 17:20:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int x = count(s.begin(), s.end(), 'T');
    int y = count(s.begin(), s.end(), 'A') + count(s.begin(), s.end(), 'U');
    int z = count(s.begin(), s.end(), 'P');
    cout << min({x, y, z});
}
