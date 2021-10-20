//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int cnt = 0;
    string s;
    cin >> s;
    stack<char> _s;
    for (int i = 0; i < s.size (); ++i) {
        if (_s.empty () && s[i] == 'a') {
            _s.push (s[i]);
        }
        else if (!_s.empty () && _s.top () == 'a' && _s.size () == 1 && s[i] == 'z') {
            _s.push (s[i]);
        }
        else if (!_s.empty () && _s.top () == 'z' && s[i] == 'h') {
            _s.push (s[i]);
        }
        else if (!_s.empty () && _s.top () == 'h' && s[i] == 'a') {
            _s.push (s[i]);
        }
        else if (!_s.empty () && _s.top () == 'a' && s[i] == 'r' && _s.size () == 4) {
            while (!_s.empty ()) {
                _s.pop ();
            }
            cnt++;
        }
    }
    cout << cnt;
}

