//https://www.codechef.com/COOK129C/problems/CSUBS
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N, K, Cnt = 0;
        cin >> N >> K;
        vector<int> V(N);
        for (int i = 0; i < N; ++i) {
            cin >> V[i];
        }
        for (int i = 0; i < K; ++i) {
            int temp = 0, maxi = INT_MIN;
            map<int, int> M;
            for (int j = i; j < N; j += K) {
                M[V[j]]++;
                maxi = max(maxi, M[V[j]]);
                temp++;
            }
            Cnt += (temp - maxi);
        }
        cout << Cnt << "\n";
    }
}
