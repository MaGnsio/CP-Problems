//https://vjudge.net/contest/414669#problem/C
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

map<string, string> m;
map<string, vector<string>> p;

void resolve (string c, string p1, string p2)
{
    if (m.find (p1) == m.end ()) resolve (p1, p[p1][0], p[p1][1]);
    if (m.find (p2) == m.end ()) resolve (p2, p[p2][0], p[p2][1]);
    //DOMINANT --> NON-EXISTENT --> RECESSIVE
    bool has_gene = false;
    if (m[p1] != "non-existent" && m[p2] != "non-existent") has_gene = true;
    else if (m[p1] == "dominant" || m[p2] == "dominant") has_gene = true;
    if (has_gene)
    {
        if (m[p1] == "dominant" && m[p2] == "dominant") m[c] = "dominant";
        else if (m[p1] == "dominant" && m[p2] == "recessive") m[c] = "dominant";
        else if (m[p1] == "recessive" && m[p2] == "dominant") m[c] = "dominant";
        else m[c] = "recessive";
    }
    else m[c] = "non-existent";
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    string f, s;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> f >> s;
        if (s == "dominant" || s == "recessive" || s == "non-existent") m[f] = s;
        else p[s].push_back (f);
    }
    for (auto& elem : p) resolve (elem.F, elem.S[0], elem.S[1]);
    for (auto& elem : m) cout << elem.F << " " << elem.S << "\n";
}

