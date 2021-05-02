//https://vjudge.net/contest/433102#problem/D
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, t;
    while ((cin >> t >> n) && (n != 0)) {
        vector<int> v(n);
        for (auto& x : v) {
            cin >> x;
        }
        sort (v.begin (), v.end (), greater<int> ());
        set<vector<int>> ans;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sum = 0;
            vector<int> temp;
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & mask) {
                    temp.push_back (v[j]);
                    sum += v[j];
                }
            }
            if (sum == t) {
                ans.insert (temp);
            }
        }
        cout << "Sums of " << t << ":\n";
        if (ans.size () == 0) {
            cout << "NONE\n";
            continue;
        }
        for (auto it = ans.rbegin (); it != ans.rend (); ++it) {
            for (int i = 0; i < (*it).size (); ++i) {
                cout << (*it)[i];
                if (i < (*it).size () - 1) {
                    cout << "+";
                }
            }
            cout << "\n";
        }
    }
}

