/**
 *    author:  MaGnsi0
 *    created: 16.12.2023 14:14:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string, int> mp;
    mp["AB"] = mp["BA"] = 0;
    mp["BC"] = mp["CB"] = 0;
    mp["CD"] = mp["DC"] = 0;
    mp["DE"] = mp["ED"] = 0;
    mp["EA"] = mp["AE"] = 0;
    mp["AB"] = mp["BA"] = 0;
    mp["EB"] = mp["BE"] = 1;
    mp["AD"] = mp["DA"] = 1;
    mp["AC"] = mp["CA"] = 1;
    mp["BD"] = mp["DB"] = 1;
    mp["EC"] = mp["CE"] = 1;
    string x; cin >> x;
    string y; cin >> y;
    cout << (mp[x] == mp[y] ? "Yes" : "No");
}
