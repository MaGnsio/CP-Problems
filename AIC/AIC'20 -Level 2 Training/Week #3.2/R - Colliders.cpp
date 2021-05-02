//https://vjudge.net/contest/419723#problem/R
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 1e5;

vector<bool> isprime (sz + 1, true), on (sz + 1, false);
vector<ll> factors[sz + 1] = {};
set<ll> active[sz + 1] = {};

void init ()
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= sz; ++i)
    {
        if (isprime[i])
        {
            for (ll j = i; j <= sz; j += i) isprime[j] = false, factors[j].push_back (i);
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        ll x;
        char sign;
        cin >> sign >> x;
        if (sign == '-')
        {
            if (on[x] == false) cout << "Already off\n";
            else
            {
                on[x] = false;
                for (ll i = 0; i < factors[x].size (); ++i) active[factors[x][i]].erase (x);
                cout << "Success\n";
            }
        }
        else
        {
            if (on[x] == true) cout << "Already on\n";
            else
            {
                bool chk = false;
                for (ll i = 0; i < factors[x].size (); ++i) if (active[factors[x][i]].size ())
                {
                    cout << "Conflict with " << *active[factors[x][i]].begin () << "\n";
                    chk = true;
                    break;
                }
                if (chk) continue;
                on[x] = true;
                for (ll i = 0; i < factors[x].size (); ++i) active[factors[x][i]].insert (x);
                cout << "Success\n";
            }
        }
    }
}

