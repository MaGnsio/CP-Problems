/**
 *    author:  MaGnsi0
 *    created: 27.09.2023 19:58:09
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 26;

struct node {
    int w;
    array<int, M> next;
    node() {
        w = 0;
        for (int& u : next) { u = -1; }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<node> T(1);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int j = 0;
        for (char c : s) {
            T[j].w++;
            if (T[j].next[c - 'a'] == -1) {
                T[j].next[c - 'a'] = (int)T.size();
                T.push_back(node());
            }
            j = T[j].next[c - 'a'];
        }
        T[j].w++;
    }
    int ans = 0;
    function<int(int)> dfs = [&](int v) {
        if (T[v].w == k) {
            ans++;
            return 0;
        }
        if (T[v].w < k) {
            return T[v].w;
        }
        int on_me = T[v].w;
        for (int u : T[v].next) {
            if (u == -1) { continue; }
            on_me -= T[u].w;
        }
        vector<int> have(1, on_me);
        for (int u : T[v].next) {
            if (u == -1) { continue; }
            have.push_back(dfs(u));
        }
        int sum = accumulate(have.begin(), have.end(), 0);
        sort(have.rbegin(), have.rend());
        for (int x : have) {
            if (sum == k) {
                ans++;
                return 0;
            }
            if (sum < k) {
                return sum;
            }
            assert(x <= k);
            sum -= x;
            ans++;
        }
        return sum;
    };
    int x = dfs(0);
    cout << ans + !!x;
}
