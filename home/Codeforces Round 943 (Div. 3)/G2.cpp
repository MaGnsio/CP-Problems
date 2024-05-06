/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 21:11:11
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 500;

vector<int> z_function(string s) {
    int n = (int)s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i) {
        if(i < r) { z[i] = min(r - i, z[i - l]); }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) { z[i]++; }
        if(i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int L; cin >> L;
        int R; cin >> R;
        string s; cin >> s;
        vector<int> ans(n + 1);
        vector<int> z = z_function(s); 
        for (int k = 1; k <= min(M, n); ++k) {
            int low = 1, high = n;
            while (low <= high) {
                int mid = (low + high) / 2;
                int subs = 1;
                for (int i = mid; i < n; /*-*/) {
                    if (z[i] >= mid) {
                        i += mid, subs++;
                    } else { i++; }
                }
                if (subs >= k) {
                    ans[k] = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        for (int mid = 1; mid <= min(M, n); ++mid) {
            int subs = 1;
            for (int i = mid; i < n; /*-*/) {
                if (z[i] >= mid) {
                    i += mid, subs++;
                } else { i++; }
            }
            ans[subs] = max(ans[subs], mid);
        }
        for (int i = n - 1; i > 0; --i) {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        for (int i = L; i <= R; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
