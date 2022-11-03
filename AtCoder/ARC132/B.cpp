/**
 *    author:  MaGnsi0
 *    created: 31.12.2021 18:30:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto solve = [&](vector<int> b) {
        int res = 0;
        deque<int> q;
        q.push_back(b[0]);
        for (int i = 1; i < n; ++i) {
            if (abs(q.front() - b[i]) == 1) {
                q.push_front(b[i]);
            } else {
                res = int(q.size());
                for (int j = n - 1; j >= i; --j) {
                    q.push_back(b[j]);
                }
                res += (q.front() == 1);
                break;
            }
            if (i == n - 1) {
                res = (q.front() == 1);
            }
        }
        return res;
    };
    int res = solve(a);
    reverse(a.begin(), a.end());
    res = min(res, 1 + solve(a));
    cout << res;
}
