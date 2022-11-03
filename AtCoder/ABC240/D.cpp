/**
 *    author:  MaGnsi0
 *    created: 23.02.2022 01:32:48
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
    int cur_sz = 0;
    stack<pair<int, int>> s;
    function<void()> clean = [&]() {
        if (s.empty()) {
            return;
        }
        if (s.top().first == s.top().second) {
            cur_sz -= s.top().second;
            s.pop();
        }
        return;
    };
    for (int i = 0; i < n; ++i) {
        clean();
        if (!s.empty() && s.top().first == a[i]) {
            s.top().second++;
        } else {
            s.push({a[i], 1});
        }
        clean();
        cout << ++cur_sz << "\n";
    }
}
