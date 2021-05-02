//https://codeforces.com/contest/1505/problem/C
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
    string s;
    cin >> s;
    vector<int> v;
    for (auto& x : s) v.push_back (int (x - 'A'));
    for (int i = 2; i < v.size (); ++i) if (v[i] != (v[i - 1] + v[i - 2]) % 26)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
}

