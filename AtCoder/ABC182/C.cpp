//https://atcoder.jp/contests/abc182/tasks/abc182_c
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    int f[3] = {};
    for (auto& x : s) {
        f[(x - '0') % 3]++;
    }
    int r = (f[1] + 2 * f[2]) % 3, k = f[0] + f[1] + f[2], ans;
    if (!r) ans = 0;
    else if (r == 1) {
        if (f[1]) {
            if (k == 1) ans = -1;
            else ans = 1;
        }
        else {
            if (k == 2) ans = -1;
            else ans = 2;
        }
    }
    else {
        if (f[2]) {
            if (k == 1) ans = -1;
            else ans = 1;
        }
        else {
            if (k == 2) ans = -1;
            else ans = 2;
        }
    }
    cout << ans;
}

