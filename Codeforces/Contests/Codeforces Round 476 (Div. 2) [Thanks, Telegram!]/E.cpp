/**
 *    author:  MaGnsi0
 *    created: 02.10.2023 21:39:35
**/
#include <bits/stdc++.h>

using namespace std;

struct node {
    bool end;
    int64_t height;
    array<int, 26> next;
    multiset<int> heights;
    node(int64_t _height) {
        end = false;
        height = _height;
        for (int& j : next) { j = -1; }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<node> T(1, node(0));
    function<void(string)> insert = [&](string s) {
        int j = 0, h = 1;
        for (char c : s) {
            if (T[j].next[c - 'a'] == -1) {
                T[j].next[c - 'a'] = (int)T.size();
                T.emplace_back(h);
            }
            j = T[j].next[c - 'a'];
            assert(T[j].height == h++);
        }
        T[j].end = true;
    };
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        insert(s);
    }
    function<void(int)> dfs = [&](int v) {
        int large = -1;
        for (int u : T[v].next) {
            if (u == -1) { continue; }
            dfs(u);
            if (large == -1 || (int)T[large].heights.size() < (int)T[u].heights.size()) {
                large = u;
            }
        }
        if (large != -1) {
            swap(T[v].heights, T[large].heights);
        }
        if (T[v].end) {
            T[v].heights.insert(T[v].height);
        }
        for (int u : T[v].next) {
            if (u == -1) { continue; }
            if (u == large) { continue; }
            for (int64_t h : T[u].heights) {
                T[v].heights.insert(h);
            }
        }
        if (v && !T[v].end && !T[v].heights.empty()) {
            T[v].heights.erase(T[v].heights.find(*T[v].heights.rbegin()));
            T[v].heights.insert(T[v].height);
        }
    };
    dfs(0);
    int64_t ans = 0;
    for (int64_t h : T[0].heights) {
        ans += h;
    }
    cout << ans;
}
