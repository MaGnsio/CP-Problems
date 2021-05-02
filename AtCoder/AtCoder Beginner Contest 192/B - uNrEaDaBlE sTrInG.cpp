//https://atcoder.jp/contests/abc192/tasks/abc192_b
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
    for (int i = 0; i < s.size (); i += 2) if (!(s[i] >= 'a' && s[i] <= 'z')) return cout << "No", 0;
    for (int i = 1; i < s.size (); i += 2) if (!(s[i] >= 'A' && s[i] <= 'Z')) return cout << "No", 0;
    cout << "Yes";
}

