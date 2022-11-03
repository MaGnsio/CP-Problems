//https://atcoder.jp/contests/abc182/tasks/abc182_b
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1001;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, cnt = 0, ans = 0;
    cin >> n;
    int a[n], g[sz] = {};
    for (auto& x : a) cin >> x;
    for (int i = 1; i < sz; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] % i == 0) {
                g[i]++;
            }
        }
    }
    for (int i = 2; i < sz; ++i) {
        if (g[i] > cnt) {
            cnt = g[i];
            ans = i;
        }
    }
    cout << ans;
}

