//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/O
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool comp (pair<int, string> a, pair<int, string> b) {return ((a.F > b.F) || (a.F == b.F && a.S < b.S));}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string s;
    cin >> s >> n;
    unordered_map<string, int> m, k;
    k["posted"] = 15, k["commented"] = 10, k["likes"] = 5;
    cin.ignore ();
    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        string t, a = "", b = "", c = "";
        getline (cin, t);
        while (t[j] != ' ') a.push_back (t[j]), j++;
        j++;
        while (t[j] != ' ') b.push_back (t[j]), j++;
        j++;
        while (t[j] != ' ' && j < t.size ()) c.push_back (t[j]), j++;
        if (c == "on")
        {
            c.clear ();
            j++;
            while (t[j] != '\'') c.push_back (t[j]), j++;
        }
        else c.erase (c.end () - 2, c.end ());
        if (a == s && c != s) m[c] += k[b];
        else if (c == s && a != s) m[a] += k[b];
        else
        {
            if (a != s && m.find (a) == m.end ()) m[a] = 0;
            if (c != s && m.find (c) == m.end ()) m[c] = 0;
        }
    }
    vector<pair<int, string>> v;
    for (auto& x : m) v.push_back ({x.S, x.F});
    sort (v.begin (), v.end (), comp);
    for (auto& x : v) cout << x.S << "\n";
}

