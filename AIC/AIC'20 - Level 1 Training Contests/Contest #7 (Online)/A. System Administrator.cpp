//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll N, A = 0, B = 0, SA = 0, SB = 0;
    cin >> N;
    while (N--)
    {
        ll s, x, y;
        cin >> s >> x >> y;
        if (s == 1) A += 10, SA += x;
        else B += 10, SB += x;
    }
    if (2 * SA >= A) cout << "LIVE\n";
    else cout << "DEAD\n";
    if (2 * SB >= B) cout << "LIVE\n";
    else cout << "DEAD\n";
}

