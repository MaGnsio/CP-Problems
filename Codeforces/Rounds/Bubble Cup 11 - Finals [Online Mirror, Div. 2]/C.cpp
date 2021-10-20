/**
 *    author:  MaGnsi0
 *    created: 31/08/2021 02:05:06
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    map<int, int> p;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        if (i) {
            p[s]++;
        } else {
            v[--d] += s;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == d) {
            continue;
        }
        if (v[i] > v[d]) {
            int x = p.rbegin() -> first;
            v[i] += x;
            p[x]--;
            if (!p[x]) {
                p.erase(x);
            }
        } else {
            int x;
            if (v[d] - v[i] > p.begin() -> first) {
                x = p.begin() -> first;
            } else {
                x = p.lower_bound(v[d] - v[i]) -> first;
            }
            v[i] += x;
            p[x]--;
            if (!p[x]) {
                p.erase(x);
            }
        }
    }
    int rank = 1;
    for (int i = 0; i < n; ++i) {
        if (i == d) {
            continue;
        }
        if (v[i] > v[d]) {
            rank++;
        }
    }
    cout << rank;
}
