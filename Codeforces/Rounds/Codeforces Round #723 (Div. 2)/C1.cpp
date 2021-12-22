/**
 *    author:  MaGnsi0
 *    created: 07.11.2021 20:52:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> a;
    long long h = 0;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        h += x;
        a.push(x);
        while (h < 0) {
            h -= a.top();
            a.pop();
        }
    }
    cout << (int)a.size();
}
