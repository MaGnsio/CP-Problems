//https://vjudge.net/contest/434102#problem/M
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome (string s) {
    for (int i = 0; i < s.size () / 2; ++i) {
        if (s[i] != s[s.size () - i - 1]) {
            return false;
        }
    }
    return true;
}

void solve (vector<string>& v, string& s, int i = 0, int j = 0) {
    if (i == s.size ()) {
        return;
    }
    if (j == s.size ()) {
        solve (v, s, i + 1, i + 1);
    } else {
        if (isPalindrome (s.substr (i, j - i + 1))) {
            v.push_back (s.substr (i, j - i + 1));
        }
        solve (v, s, i, j + 1);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    vector<string> v;
    solve (v, s);
    sort (v.begin (), v.end ());
    for (auto& x : v) {
        cout << x << "\n";
    }
}

