//https://vjudge.net/contest/436257#problem/E
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 1) {
        return 2;
    } else if (n == 2) {
        return 4;
    }
    return (solve(n - 1) + solve(n - 2));
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    cout << solve(N);
}

