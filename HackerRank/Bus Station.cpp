/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 14:43:09
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, sum = 0;
    cin >> n;
    vector<int> v(n), factors;
    for (auto& x : v) {
        cin >> x;
        sum += x;
    }
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            factors.push_back(i);
            if (sum != i * i) {
                factors.push_back(sum / i);
            }
        }
    }
    for (int i = 0; i < factors.size(); ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            x += v[j];
            if (x == factors[i]) {
                x = 0;
            } else if (x > factors[i] || (j == n - 1 && x < factors[i])) {
                factors[i] = -1;
                break;
            }
        }
    }
    vector<int> ans;
    for (auto& x : factors) {
        if (x != -1) {
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto& x : ans) {
        cout << x << " ";
    }
}
