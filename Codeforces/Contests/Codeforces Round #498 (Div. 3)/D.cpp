/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 23:58:22
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, cnt = 0;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n / 2; ++i) {
        map<char, int> mp;
        mp[s[i]]++, mp[s[n - i - 1]]++;
        mp[t[i]]++, mp[t[n - i - 1]]++;
        if (mp.size() == 4) {
            cnt += 2;
        } else if (mp.size() == 3) {
            cnt += 1 + (s[i] == s[n - i - 1]);
        } else if (mp.size() == 2) {
            cnt += (mp[s[i]] != 2);
        }
    }
    cout << cnt + (n % 2) * (s[n / 2] != t[n / 2]);
}
