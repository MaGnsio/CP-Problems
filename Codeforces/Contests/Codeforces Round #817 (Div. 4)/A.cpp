/**
 *    author:  MaGnsi0
 *    created: 30.08.2022 16:34:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        sort(s.begin(), s.end());
        cout << (s == "Timru" ? "YES" : "NO") << "\n";
    }
}
