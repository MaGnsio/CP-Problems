//https://atcoder.jp/contests/abc193/tasks/abc193_a
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
    ld a, b;
    cin >> a >> b;
    ld p = (a - b) / a * 100;
    cout << fixed << setprecision (20) << p;
}

