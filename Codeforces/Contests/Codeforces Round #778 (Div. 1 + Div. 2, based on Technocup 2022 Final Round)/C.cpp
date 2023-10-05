/**
 *    author:  MaGnsi0
 *    created: 20.03.2022 13:30:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        multiset<long long> s;
        for (int i = 0; i < n; ++i) {
            s.insert(a[i]);
        }
        vector<long long> cur = {sum};
        while (s.size()) {
            bool changes = false;
            vector<long long> b;
            if (cur.size() > n) {
                break;
            }
            for (int i = 0; i < (int)cur.size(); ++i) {
                if (s.count(cur[i])) {
                    s.erase(s.find(cur[i]));
                    changes = true;
                } else {
                    if (cur[i] >= 2) {
                        b.push_back(cur[i] / 2);
                        b.push_back(cur[i] - cur[i] / 2);
                        changes = true;
                    } else {
                        changes = false;
                        break;
                    }
                }
            }
            if (!changes) {
                break;
            }
            cur = b;
        }
        cout << ((int)s.size() ? "NO" : "YES") << "\n";
    }
}
