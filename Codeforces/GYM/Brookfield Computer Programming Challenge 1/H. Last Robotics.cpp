//https://codeforces.com/gym/102680/problem/H
#include <bits/stdc++.h>
using namespace std;
const long long sz = 1e18;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        bitset<64> v(n - 1);
        cout << (v.count () & 1 ? "Blue\n" : "Red\n");
    }
}

