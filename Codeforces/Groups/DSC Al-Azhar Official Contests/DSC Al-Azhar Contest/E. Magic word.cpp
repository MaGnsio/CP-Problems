//https://codeforces.com/group/iryj9wI6zY/contest/323491/problem/E
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k;
    string s, t = "";
    cin >> n >> k >> s;
    vector<int> f(26, 0);
    for (int i = 0; i < k; ++i) {
        f[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (f[i] == *max_element (f.begin (), f.end ())) {
            t.push_back ('a' + i);
            break;
        }
    }
    for (int i = k; i < n; ++i) {
        f[s[i - k] - 'a']--;
        f[s[i] - 'a']++;
        for (int j = 0; j < 26; ++j) {
            if (f[j] == *max_element (f.begin (), f.end ())) {
                t.push_back ('a' + j);
                break;
            }
        }
    }
    cout << t;
}

