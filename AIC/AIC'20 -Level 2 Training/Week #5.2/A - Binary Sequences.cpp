//https://vjudge.net/contest/435128#problem/A
#include <bits/stdc++.h>
using namespace std;

string s = "";
void solve(int n) {
    if (n == 0) {
        cout << s << "\n";
        return;
    }
    s += "0";
    solve(n - 1);
    s.pop_back();
    s += "1";
    solve(n - 1);
    s.pop_back();
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        solve(N);
    }
}

