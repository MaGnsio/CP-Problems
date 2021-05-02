//https://atcoder.jp/contests/abc191/tasks/abc191_a
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
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    cout << (v * t <= d && d <= v * s ? "No" : "Yes");
}

