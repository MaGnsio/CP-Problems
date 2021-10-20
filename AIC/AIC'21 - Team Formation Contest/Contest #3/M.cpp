/**
 *    author:  MaGnsi0
 *    created: 18/07/2021 13:23:02
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        x = (x < 0 ? -1 : 1);
    }
    vector<int> neg;
    neg.push_back(-1);
    for (int i = 0; i < n; ++i) {
        if (v[i] < 0) {
            neg.push_back(i);
        }
    }
    neg.push_back(n);
    int nn = 0;
    vector<int> h = neg;
    for (int i = 1; i < neg.size(); ++i) {
        if (i & 1) {
            h[i] = h[i - 1] + h[i];
        } else {
            h[i] = h[i - 1] - h[i];
        }
    }
    for (int i = 1; i < neg.size() - 1; ++i) {
        int b = (neg[i] - neg[i - 1]);
        int c = (h[h.size() - (((i & 1) && (h.size() & 1)) || ((i % 2 == 0) && (h.size() % 2 == 0)) ? 1 : 2)] - h[i - 1]) * (i & 1 ? -1 : 1);
        nn += (b * c);
    }
    cout << nn << " " << (n * (n + 1) / 2) - nn;
}
