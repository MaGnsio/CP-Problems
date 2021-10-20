//https://codeforces.com/gym/102680/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    cin.ignore ();
    for (int t = 0; t < n; ++t) {
        string x, y;
        getline (cin, x);
        getline (cin, y);
        string a = "", b = "";
        for (int i = x.size () - 1; i >= 0; --i) {
            if (x[i] == ' ') break;
            a.push_back (x[i]);
        }
        for (int i = y.size () - 1; i >= 0; --i) {
            if (y[i] == ' ') break;
            b.push_back (y[i]);
        }
        reverse (a.begin (), a.end ());
        reverse (b.begin (), b.end ());
        cout << "Uh! " << b << "-" << a << "!\n";
    }
}

