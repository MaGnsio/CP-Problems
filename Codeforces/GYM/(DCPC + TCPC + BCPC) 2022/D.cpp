/**
 *    author:  MaGnsi0
 *    created: 01.08.2022 22:51:13
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 1e3 + 3, MAX = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int64_t n, k;
        cin >> n >> k;
        int64_t sum = 0;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            if (k == 1) {
                break;
            }
            int64_t lg = log2(k);
            if ((1LL << lg) < k) {
                lg++;
            }
            if (n - sum - 1 >= lg) {
                a.push_back(0);
                sum++;
                k--;
                continue;
            }
            int64_t x = 0, prev = 1;
            while (prev + (1LL << (n - sum - x - 1)) < k) {
                assert(n - sum - x - 1 >= 0);
                prev += (1LL << (n - sum - x - 1));
                x++;
            }
            sum += x + 1;
            a.push_back(x);
            k -= prev;
        }
        cout << s;
        for (int i = 0; i < (int)a.size(); ++i) {
            cout << "-C" << setw(4) << setfill('0') << a[i];
        }
        cout << "\n";
    }
}
