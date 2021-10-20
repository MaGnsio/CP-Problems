//https://codeforces.com/gym/102680/problem/D
#include <bits/stdc++.h>
using namespace std;

bool isprime (long long x) {
    if (x < 1) {
        return false;
    }
    if (x == 2 || x == 3) {
        return true;
    }
    if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }
    for (long long i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        if (x == 1) {
            cout << "Neither\n";
        }
        else if (isprime (x)) {
            cout << "Prime\n";
        }
        else {
            cout << "Composite\n";
        }
    }
}

