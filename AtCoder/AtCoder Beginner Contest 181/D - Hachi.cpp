//https://atcoder.jp/contests/abc181/tasks/abc181_d
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
    vector<int> f (10, 0);
    vector<string> v;
    string s;
    cin >> s;
    for (auto& x : s) f[x - '0']++;
    for (int i = 1; i < 1000; ++i) if (i % 8 == 0)
    {
        v.push_back (to_string (i));
    }
    for (int i = 0; i < v.size (); ++i)
    {
        if (v[i].size () < min (3, (int) s.size ())) continue;
        int chk = 1;
        vector<int> tmp (10, 0);
        for (auto& x : v[i]) tmp[x - '0']++;
        for (int i = 0; i < 10; ++i) if (f[i] < tmp[i])
        {
            chk = 0;
            break;
        }
        if (chk)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}

