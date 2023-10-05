/**
 *    author:  MaGnsi0
 *    created: 30/09/2021 01:47:25
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<long long> f(n);
        f[0] = (s[0] - '0');
        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + (s[i] - '0');
        }
        map<int, long long> mp;
        mp[0]++;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            res += mp[f[i] - (i + 1)]++;
        }
        cout << res << "\n";
    }
}
