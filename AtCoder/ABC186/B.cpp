//https://atcoder.jp/contests/abc186/tasks/abc186_b
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
    int h, w, cnt = 0;
    cin >> h >> w;
    int a[h * w];
    for (auto& x : a) cin >> x;
    int m = *min_element (a, a + h * w);
    for (auto& x : a) cnt += (x - m);
    cout << cnt;
}

