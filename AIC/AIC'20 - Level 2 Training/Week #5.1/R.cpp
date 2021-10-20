//https://vjudge.net/contest/434102#problem/R
#include <bits/stdc++.h>
using namespace std;

bool sorted (vector<int>& v, int l, int r) {
    for (int i = l; i < r; ++i) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve (vector<int>& v, int& ans, int l, int r) {
    if (sorted (v, l, r)) {
        ans = max (ans, r - l + 1);
        return;
    }
    int mid = (l + r) / 2;
    solve (v, ans, l, mid);
    solve (v, ans, mid + 1, r);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = INT_MIN;
    cin >> n;
    vector<int> v (n);
    for (auto& x : v) {
        cin >> x;
    }
    solve (v, ans, 0, n - 1);
    cout << ans;
}

