//https://vjudge.net/contest/434102#problem/O
#include <bits/stdc++.h>
using namespace std;

void solve (int n, int m, vector<int> temp, vector<int>& v, set<vector<int>>& s, int i = 0, int sum = 0) {
    if (i == n) {
        if (sum == m) {
            s.insert (temp);
        }
        return;
    }
    solve (n, m, temp, v, s, i + 1, sum);
    temp.push_back (v[i]);
    solve (n, m, temp, v, s, i + 1, sum + v[i]);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v (n), temp;
        for (auto& x : v) {
            cin >> x;
        }
        sort (v.begin (), v.end (), greater<int> ());
        set<vector<int>> s;
        solve (n, m, temp, v, s);
        if (s.empty ()) {
            cout << "NONE\n";
        } else {
            for (auto& x : s) {
                for (auto& y : x) {
                    cout << y << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }
}

