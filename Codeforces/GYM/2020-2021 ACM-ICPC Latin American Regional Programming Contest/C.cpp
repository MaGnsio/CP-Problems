/**
 *    author:  MaGnsi0
 *    created: 06/10/2021 00:31:03
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve(vector<int> v) {
    int n = (int)v.size(), res = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q1;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            continue;
        }
        if (v[i] > 0) {
            q1.push({i, v[i]});
            v[i] = 0;
        } else {
            while (v[i] != 0 && !q1.empty()) {
                int x = q1.top().second, j = q1.top().first;
                q1.pop();
                int amount = min(abs(v[i]), x);
                res += amount * abs(j - i);
                v[i] += amount;
                x -= amount;
                if (x) {
                    q1.push({j, x});
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] == 0) {
            continue;
        }
        if (v[i] > 0) {
            q1.push({i, v[i]});
            v[i] = 0;
        } else {
            while (v[i] != 0 && !q1.empty()) {
                int x = q1.top().second, j = q1.top().first;
                q1.pop();
                int amount = min(abs(v[i]), x);
                res += amount * (i + n - j);
                v[i] += amount;
                x -= amount;
                if (x) {
                    q1.push({j, x});
                }
            }
        }
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int x = accumulate(v.begin(), v.end(), 0) / n;
    for (int i = 0; i < n; ++i) {
        v[i] = v[i] - x;
    }
    int a = solve(v);
    reverse(v.begin(), v.end());
    int b = solve(v);
    cout << min(a, b);
}
