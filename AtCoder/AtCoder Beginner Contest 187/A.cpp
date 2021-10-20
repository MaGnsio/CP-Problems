//https://atcoder.jp/contests/abc187/tasks/abc187_a
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
    int a = 0, b = 0;
    string s, t;
    cin >> s >> t;
    for (auto& x : s) a += (x - '0');
    for (auto& x : t) b += (x - '0');
    cout << max (a, b);
}

