//https://codeforces.com/gym/102953/problem/1
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
    ll n, c = 0, o = 0, d = 0, e = 0, r = 0, a = 0, m = 0, s = 0;
    string _s;
    cin >> n >> _s;
    for (auto& x : _s) c += (x == 'c'), o += (x == 'o'), d += (x == 'd'), e += (x == 'e'), r += (x == 'r'), a += (x == 'a'), m += (x == 'm'), s += (x == 's');
    cout << min ({c, o, d, e, r, a, m, s});
}

