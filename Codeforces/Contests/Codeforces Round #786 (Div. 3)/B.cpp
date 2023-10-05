/**
 *    author:  MaGnsi0
 *    created: 02.05.2022 20:54:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, int> mp;
    for (char x = 'a'; x <= 'z'; ++x) {
        for (char y = 'a'; y <= 'z'; ++y) {
            if (x == y) {
                continue;
            }
            string s = "";
            s += x;
            s += y;
            mp[s] = (int)mp.size() + 1;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << mp[s] << "\n";
    }
}
