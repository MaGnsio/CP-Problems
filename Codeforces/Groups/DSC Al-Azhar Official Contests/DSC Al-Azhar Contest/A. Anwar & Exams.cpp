//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/A
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    vector<int> v(5, 0);
    string s;
    cin >> n >> s;
    for (auto& c : s) {
        v[0] += (c == 'a');
        v[1] += (c == 'b');
        v[2] += (c == 'c');
        v[3] += (c == 'd');
        v[4] += (c == 'e');
    }
    cout << *min_element (v.begin (), v.end ()) << " " << *max_element (v.begin (), v.end ());
}

