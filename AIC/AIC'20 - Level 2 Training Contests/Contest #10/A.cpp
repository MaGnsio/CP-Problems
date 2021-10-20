//https://vjudge.net/contest/436257#problem/A
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int mini = INT_MAX;
    string S;
    cin >> S;
    int N = S.size();
    for (int mask = 1; mask < (1 << N); ++mask) {
        int sum = 0, cnt = N;
        for (int j = 0; j < N; ++j) {
            if ((1 << j) & mask) {
                sum += (S[j] - '0');
                cnt--;
            }
        }
        if (sum && sum % 3 == 0) {
            mini = min(mini, cnt);
        }
    }
    cout << (mini == INT_MAX ? -1 : mini);
}

