/**
 *    author:  MaGnsi0
 *    created: 05.05.2024 15:06:41
**/
#include <bits/stdc++.h>

using namespace std;

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
        int k; cin >> k;
        int _; cin >> _;
        string s; cin >> s;
        vector<int> z = z_function(s);
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int subs = 1;
            for (int i = mid; i < n; /*-*/) {
                if (z[i] >= mid) {
                    i += mid, subs++;
                } else { i++; }
            }
            if (subs >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}
