//https://codeforces.com/contest/1504/problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s, x = "", y = "";
        cin >> n >> s;
        int cnt = count (s.begin (), s.end (), '1'), cur = 0;
        if (cnt & 1 || s[0] == '0' || s.back () == '0') {
            cout << "NO\n";
            continue;
        }
        bool b = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                x.push_back (2 * cur < cnt ? '(' : ')');
                y.push_back (2 * cur < cnt ? '(' : ')');
                cur++;
            }
            else {
                x.push_back (b ? '(' : ')');
                y.push_back (b ? ')' : '(');
                b = !b;
            }
        }
        cout << "YES\n" << x << "\n" << y << "\n";
    }
}

