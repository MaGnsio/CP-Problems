//https://codeforces.com/contest/1512/problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> v(n, vector<char> (n));
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v[i][j];
                if (v[i][j] == '*') {
                    a.push_back (i);
                    a.push_back (j);
                }
            }
        }
        if (a[0] != a[2] && a[1] != a[3]) {
            v[a[0]][a[3]] = '*';
            v[a[2]][a[1]] = '*';
        }
        else if (a[0] == a[2]) {
            v[(a[0] + 1) % n][a[1]] = '*';
            v[(a[2] + 1) % n][a[3]] = '*';
        }
        else {
            v[a[0]][(a[1] + 1) % n] = '*';
            v[a[2]][(a[3] + 1) % n] = '*';
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << v[i][j];
            cout << "\n";
        }
    }
}

