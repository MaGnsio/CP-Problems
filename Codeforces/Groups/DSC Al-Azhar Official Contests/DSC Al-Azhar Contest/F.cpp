//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/F
#include <bits/stdc++.h>
using namespace std;

const int sz = 1000001;

vector<int> v(sz, 0);

void init () {
    for (int i = 2; i < sz; ++i) {
        int cur = i;
        for (int j = 2; j * j <= cur; ++j) {
            if (cur % j == 0) {
                v[i]++;
                while (cur % j == 0)
                    cur /= j;
            }
        }
        if (cur > 1) v[i]++;
    }
    for (int i = 1; i < sz; ++i) {
        v[i] += v[i - 1];
    }
}


int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init ();
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap (l, r);
        cout << v[r] - v[l - 1] << "\n";
    }
}

