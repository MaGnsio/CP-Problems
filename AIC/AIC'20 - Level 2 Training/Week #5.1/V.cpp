//https://vjudge.net/contest/434102#problem/V
#include <bits/stdc++.h>
using namespace std;

void solve (long long n, long long& ans, string s) {
    if (stoll (s) >= n && count (s.begin (), s.end (), '4') == count (s.begin (), s.end (), '7')) {
        ans = min (ans, stoll (s));
    }
    if (s.size () > to_string (n).size () + 2) {
        return;
    }
    solve (n, ans, s + "4");
    solve (n, ans, s + "7");
    s.pop_back ();
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, ans = LLONG_MAX;
    cin >> n;
    n = max (5LL, n);
    solve (n, ans, "0");
    cout << ans;
}

