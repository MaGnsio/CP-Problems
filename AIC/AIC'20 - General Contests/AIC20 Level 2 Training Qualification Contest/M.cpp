//https://codeforces.com/group/nVgev28wQI/contest/308101/problem/M
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
    //input
    ll n, ctr = 1, max_ctr = 1;
    string s;
    cin >> n >> s;
    //checking for passcodes length
    for (ll i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1]) ctr++;
        else max_ctr = max (max_ctr, ctr), ctr = 1;
    }
    max_ctr = max (max_ctr, ctr);
    //if passcodes length = 1 then every character is a passcode
    if (max_ctr == 1)
    {
        string ans;
        sort (s.begin (), s.end ());
        for (ll i = 0; i < n; ++i) if (s[i] != s[i - 1] || i == 0) ans += s[i]; //filtering
        cout << ans.size () << "\n";
        for (auto& elem : ans) cout << elem << "\n";
    }
    else
    {
        vector<string> v;
        set<string> u;
        string temb;
        temb += s[0];
        for (ll i = 1; i < n; ++i) //filtering
        {
            if (s[i] == s[i - 1]) temb += s[i];
            else if (temb.size () == max_ctr)
            {
                if (u.count (temb) == 0) v.push_back (temb);
                u.insert (temb);
                temb.clear ();
                temb += s[i];
            }
            else
            {
                temb.clear ();
                temb += s[i];
            }
        }
        if (temb.size () == max_ctr && u.count (temb) == 0) v.push_back (temb);
        sort (v.begin (), v.end ());
        cout << v.size () << "\n";
        for (auto& elem : v) cout << elem << "\n";
    }
}

