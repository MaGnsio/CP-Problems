//https://vjudge.net/contest/434102#problem/T
#include <bits/stdc++.h>
using namespace std;

void solve (int n, int i, int sum, vector<int>& v, vector<vector<char>>& t, vector<char>& temp, char k) {
    if (i == n) {
        if (sum == 0) {
            t.push_back (temp);
        }
        return;
    }
    if (k == '+') {
        sum += v[i];
        temp.push_back ('+');
    } else {
        sum -= v[i];
        temp.push_back ('-');
    }
    solve (n, i + 1, sum, v, t, temp, '+');
    solve (n, i + 1, sum, v, t, temp, '-');
    temp.pop_back ();
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> v (n);
    vector<char> s (n, '+'), temp;
    vector<vector<char>> t;
    for (int i = 0; i < n; ++i) {
        if (i) {
            cin >> s[i];
        }
        cin >> v[i];
    }
    solve (n, 0, 0, v, t, temp, '+');
    if (t.empty ()) {
        cout << -1;
        return 0;
    }
    for (auto& x : t) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += (x[i] != s[i]);
        }
        ans = min (ans, cur);
    }
    cout << ans;
}

