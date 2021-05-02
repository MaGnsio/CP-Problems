//https://atcoder.jp/contests/abc191/tasks/abc191_b
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
    int n, x;
    cin >> n >> x;
    vector<int> v;
    while (n--)
    {
        ll a;
        cin >> a;
        if (a != x) v.push_back (a);
    }
    for (auto& a : v) cout << a << " ";
}

