//
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
    ll t;
    cin >> t;
    while (t--)
    {
        //input
        ll n;
        cin >> n;
        vector<ll> v (n);
        for (auto& x : v) cin >> x;
        //check if all elements are equal (c = 0 --> m = inf)
        bool chk0 = 1;
        for (ll i = 0; i < n - 1; ++i) if (v[i] != v[i + 1])
        {
            chk0 = 0;
            break;
        }
        if (chk0)
        {
            cout << 0 << "\n";
            continue;
        }
        //chk if there two equal consecutive numbers (then we can't pick a suitable m as c != 0)
        bool chk1 = 0;
        for (ll i = 0; i < n - 1; ++i) if (v[i] == v[i + 1])
        {
            chk1 = 1;
            break;
        }
        if (chk1)
        {
            cout << -1 << "\n";
            continue;
        }
        //0 <= c < m --> v[i] = (v[i - 1] + c) % m = v[i - 1] + c or v[i - 1] + c - m
        //pos = c, neg = c - m --> m = c - (c - m) : pos & neg are two unique differences in the array
        ll pos = 0, neg = 0;
        bool chk2 = 0;
        for (ll i = 0; i < n - 1; ++i)
        {
            if (v[i + 1] - v[i] > 0)
            {
                if (pos == 0 || pos == v[i + 1] - v[i]) pos = v[i + 1] - v[i];
                else
                {
                    chk2 = 1;
                    break;
                }
            }
            else
            {
                if (neg == 0 || neg == v[i + 1] - v[i]) neg = v[i + 1] - v[i];
                else
                {
                    chk2 = 1;
                    break;
                }
            }
        }
        //chk whether the differences differ or not
        if (chk2)
        {
            cout << -1 << "\n";
            continue;
        }
        //if any of the differences does not exist then m can be arbitrary large
        if (!neg || !pos)
        {
            cout << 0 << "\n";
            continue;
        }
        //chk if those m & c values generate the given sequence
        //s >= 0 --> m > max (v[i])
        ll m = pos - neg, c = pos;
        bool chk4 = 0;
        for (ll i = 1; i < n; ++i) if (v[i] != (v[i - 1] + c) % m)
        {
            chk4 = 1;
            break;
        }
        if (chk4 || m <= *max_element (v.begin (), v.end ()))
        {
            cout << -1 << "\n";
            continue;
        }
        cout << m << " " << c << "\n";
    }
}
