//https://vjudge.net/contest/436257#problem/D
#include <bits/stdc++.h>
using namespace std;

void solve(long long& N, int& cnt, string S = "0") {
    if (stoll(S) > N) {
        return;
    }
    if ((stoll(S) != 0 && S[1] == '0') || (stoll(S) == 0 && S.size() > 1)) {
        return;
    }
    set<char> U;
    for (int i = 1; i < S.size(); ++i) {
        U.insert(S[i]);
    }
    if (U.size() > 2) {
        return;
    }
    if(stoll(S) <= N) {
        cnt++;
    }
    for (int i = 0; i < 10; ++i) {
        solve(N, cnt, S + to_string(i));
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long N;
    int cnt = -1;
    cin >> N;
    solve(N, cnt);
    cout << cnt;
}

