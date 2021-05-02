//https://vjudge.net/contest/433102#problem/R
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    unordered_set<int> ans = {v[0]}, cur = {v[0]};
    for (int i = 1; i < n; ++i) {
        unordered_set<int> temp = {v[i]};
        for (auto& x : cur) {
            temp.insert (x | v[i]);
        }
        cur = temp;
        ans.insert (cur.begin (), cur.end ());
    }
    cout << ans.size ();
}

