//https://codeforces.com/problemset/problem/1353/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

void solve ()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort (b.begin (), b.end (), greater<int> ());
    for (ll i = 0; i < min (n, k); ++i) a.push_back (b[i]);
    sort (a.begin (), a.end (), greater<int> ());
    for (ll i = 0; i < n; ++i) sum += a[i];
    cout << sum << "\n";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
        solve ();
}

