//https://atcoder.jp/contests/abc184/tasks/abc184_c
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c && b == d) cout << 0;
    else if (a + b == c + d || a - b == c - d || abs (a - c)  + abs (b - d) <= 3) cout << 1;
    else if ((a + b + c + d) % 2 == 0 || abs (a - c) + abs (b - d) <= 6 || abs ((a + b) - (c + d)) <= 3 || abs ((a - c) - (b - d)) <= 3) cout << 2;
    else cout << 3;
}

