//https://vjudge.net/contest/433801#problem/F
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string a, b;
    cin >> a >> b;
    if (a.size () != b.size ()) {
        cout << "NO";
        return 0;
    }
    int O = 0, o = 0;
    for (auto& x : a) {
        O += (x == '1');
    }
    for (auto& x : b) {
        o += (x == '1');
    }
    if ((O && !o) || (!O && o)) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}

