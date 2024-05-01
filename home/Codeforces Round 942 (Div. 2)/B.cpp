/**
 *    author:  MaGnsi0
 *    created: 30.04.2024 17:42:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //uud => ud
    //dud => uu
    //duu => ud
    //ud  => d
    //uu  => u
    //du  => d
    //ud  => u
    //uuu => dd
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        int res = count(s.begin(), s.end(), 'U');
        cout << (res & 1 ? "YES" : "NO") << "\n";
    }
}
