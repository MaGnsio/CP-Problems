//https://codeforces.com/contest/1512/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, idx;
        cin >> n;
        vector<int> v(n);
        set<int> s;
        for (auto& x : v) {
            cin >> x;
            s.insert (x);
        }
        int x = (count (v.begin (), v.end (), *s.begin ()) == 1 ? *s.begin () : *s.rbegin ());
        for (idx = 0; idx < n; ++idx) if (v[idx] == x) {
            break;
        }
        cout << idx + 1 << "\n";
    }
}

