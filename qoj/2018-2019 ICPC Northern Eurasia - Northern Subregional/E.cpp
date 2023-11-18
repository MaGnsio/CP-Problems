/**
 *    author:  MaGnsi0
 *    created: 28.09.2023 23:57:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    cin.ignore();
    map<string, int> mp;
    for (int i = 0; i < k; ++i) {
        string in; getline(cin, in);
        stringstream sin(in);
        int count = 0;
        string s;
        while(sin >> s) {
            count++;
        }
        mp[s] = max(mp[s], count);
    }
    int ans = 0;
    for (auto [_, count] : mp) {
        ans += count;
    }
    cout << (ans <= n ? "YES" : "NO");
}
