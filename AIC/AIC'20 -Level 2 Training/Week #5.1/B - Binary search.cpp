//https://vjudge.net/contest/434102#problem/B
#include <bits/stdc++.h>
using namespace std;

int bs (int x, vector<int> &v, int l, int r) {
    if (l > r) {
        return -1;
    }
    int mid = (r + l) / 2;
    if (v[mid] == x) {
        return mid + 1;
    } else if (v[mid] < x) {
        return bs (x, v, mid + 1, r);
    } else {
        return bs (x, v, l, mid - 1);
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, q;
    cin >> n;
    vector<int> v (n);
    for (auto& x : v) {
        cin >> x;
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << bs (x, v, 0, n - 1) << "\n";
    }
}

