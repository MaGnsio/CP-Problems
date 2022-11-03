//https://atcoder.jp/contests/abc187/tasks/abc187_b
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
    int n, cnt = 0;
    cin >> n;
    pair<int, int> a[n];
    for (auto& x : a) cin >> x.F >> x.S;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (abs (a[i].S - a[j].S) <= abs (a[i].F - a[j].F)) cnt++;
        }
    }
    cout << cnt;
}

