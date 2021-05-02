//https://vjudge.net/contest/433102#problem/E
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = 1;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        bool chk = true;
        int last = -1, cnt = __builtin_popcount (mask);
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & mask) {
                if (v[j] <= last) {
                    chk = false;
                    break;
                }
                else {
                    last = v[j];
                }
            }
        }
        if (chk) {
            ans = max (ans, cnt);
        }
    }
    cout << ans;
}

