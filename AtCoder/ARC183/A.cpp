/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 15:00:45
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> solve(int n, int k) {
    if (n == 1) {
        return vector<int>(n * k, 1);
    }
    vector<int> ans, F(n + 1, k);
    if (n % 2 == 0) {
        ans.push_back(n / 2); F[n / 2]--;
    } else {
        for (int i = 0; i < k; ++i) {
            ans.push_back((n + 1) / 2);
            F[(n + 1) / 2]--;
        }
        ans.push_back(n / 2); F[n / 2]--;
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j < F[i]; ++j) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int k; cin >> k;
    for (int x : solve(n, k)) {
        cout << x << " ";
    }
}
