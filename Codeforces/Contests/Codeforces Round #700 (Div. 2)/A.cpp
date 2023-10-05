//https://codeforces.com/contest/1480/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size (); ++i) {
            if (i & 1) {
                s[i] = (s[i] == 'z' ? 'y' : 'z');
            }
            else {
                s[i] = (s[i] == 'a' ? 'b' : 'a');
            }
        }
        cout << s << "\n";
    }
}

