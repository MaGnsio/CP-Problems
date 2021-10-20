//https://codeforces.com/gym/102757/problem/G
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, K, ans = INT_MAX;
    cin >> N >> K;
    vector<string> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    vector<int> P(K);
    iota(P.begin(), P.end(), 0);
    do {
        int maxi = INT_MIN, mini = INT_MAX;
        for (int i = 0; i < N; ++i) {
            int t = 0;
            for (int j = 0; j < K; ++j) {
                t = (t * 10) + (V[i][P[j]] - '0');
            }
            maxi = max(maxi, t);
            mini = min(mini, t);
        }
        ans = min(ans, maxi - mini);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans;
}
