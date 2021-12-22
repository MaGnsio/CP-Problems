/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 13:52:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int max = 0;
    string res;
    for (auto& [x, y] : mp) {
        if (y > max) {
            max = y;
            res = x;
        }
    }
    cout << res;
}
