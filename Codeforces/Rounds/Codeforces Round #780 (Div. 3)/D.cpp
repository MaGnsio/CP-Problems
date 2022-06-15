/**
 *    author:  MaGnsi0
 *    created: 31.03.2022 19:05:23
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
        vector<int> a(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<int> zero, two(n + 2, 0), negative(n + 2, 0);
        for (int i = 0; i < n + 2; ++i) {
            if (a[i] == 0) {
                zero.push_back(i);
            }
            two[i] += (abs(a[i]) == 2);
            negative[i] += (a[i] < 0);
        }
        vector<int> pren(n + 2, -1), sufn(n + 2, -1); 
        for (int i = 1; i < n + 2; ++i) {
            pren[i] = pren[i - 1];
            if (negative[i]) {
                pren[i] = i;
            }
        }
        for (int i = n; i >= 0; --i) {
            sufn[i] = sufn[i + 1];
            if (negative[i]) {
                sufn[i] = i;
            }
        }
        for (int i = 1; i < n + 2; ++i) {
            two[i] += two[i - 1];
            negative[i] += negative[i - 1];
        }
        tuple<int, int, int> ans = make_tuple(0, 0, n);
        for (int i = 1; i < (int)zero.size(); ++i) {
            int l = zero[i - 1] + 1, r = zero[i] - 1;
            if (l > r) {
                continue;
            }
            int cntn = negative[r] - negative[l - 1];
            if (cntn & 1) {
                int firstn = sufn[l], lastn = pren[r];
                assert(lastn != -1 && firstn != -1); 
                if (two[r] - two[firstn] > two[lastn - 1] - two[l - 1]) {
                    l = firstn + 1;
                } else {
                    r = lastn - 1;
                }
            }
            assert((negative[r] - negative[l - 1]) % 2 == 0);
            int cnt2 = two[r] - two[l - 1];
            ans = max(ans, make_tuple(cnt2, l - 1, n - r));
        }
        cout << get<1>(ans) << " " << get<2>(ans) << "\n";
    }
}
