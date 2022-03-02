/**
 *    author:  MaGnsi0
 *    created: 10.02.2022 20:53:46
**/
#include <bits/stdc++.h>

using namespace std;

struct block_world {
    int n;
    vector<int> pos;
    vector<stack<int>> blocks;
    block_world(int n) {
        this -> n = n;
        pos.resize(n);
        for (int i = 0; i < n; ++i) {
            pos[i] = i;
        }
        blocks.resize(n);
        for (int i = 0; i < n; ++i) {
            blocks[i].push(i);
        }
    }
    void op1(int a, int b) {
        while (blocks[pos[a]].top() != a) {
            int x = blocks[pos[a]].top();
            blocks[x].push(x);
            pos[x] = x;
            blocks[pos[a]].pop();
        }
        while (blocks[pos[b]].top() != b) {
            int x = blocks[pos[b]].top();
            blocks[x].push(x);
            pos[x] = x;
            blocks[pos[b]].pop();
        }
        blocks[pos[a]].pop();
        blocks[pos[b]].push(a);
        pos[a] = pos[b];
    }
    void op2(int a, int b) {
        while (blocks[pos[a]].top() != a) {
            int x = blocks[pos[a]].top();
            blocks[x].push(x);
            pos[x] = x;
            blocks[pos[a]].pop();
        }
        blocks[pos[a]].pop();
        blocks[pos[b]].push(a);
        pos[a] = pos[b];
    }
    void op3(int a, int b) {
        while (blocks[pos[b]].top() != b) {
            int x = blocks[pos[b]].top();
            blocks[x].push(x);
            pos[x] = x;
            blocks[pos[b]].pop();
        }
        stack<int> s;
        while (blocks[pos[a]].top() != a) {
            int x = blocks[pos[a]].top();
            s.push(x);
            blocks[pos[a]].pop();
        }
        blocks[pos[a]].pop();
        s.push(a);
        while (!s.empty()) {
            blocks[pos[b]].push(s.top());
            pos[s.top()] = pos[b];
            s.pop();
        }
    }
    void op4(int a, int b) {
        stack<int> s;
        while (blocks[pos[a]].top() != a) {
            int x = blocks[pos[a]].top();
            s.push(x);
            blocks[pos[a]].pop();
        }
        blocks[pos[a]].pop();
        s.push(a);
        while (!s.empty()) {
            blocks[pos[b]].push(s.top());
            pos[s.top()] = pos[b];
            s.pop();
        }
    }
    void print() {
        for (int i = 0; i < n; ++i) {
            cout << i << ":";
            stack<int> x = blocks[i], y;
            while (!x.empty()) {
                y.push(x.top());
                x.pop();
            }
            while (!y.empty()) {
                cout << " " << y.top();
                y.pop();
            }
            cout << "\n";
        }
    }
};

vector<string> translate(string s) {
    vector<string> a(4, "");
    int i = 0;
    while (s[i] != ' ') {
        a[0] += s[i++];
    }
    i++;
    while (s[i] != ' ') {
        a[1] += s[i++];
    }
    i++;
    while (s[i] != ' ') {
        a[2] += s[i++];
    }
    i++;
    while (i < (int)s.size()) {
        a[3] += s[i++];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    block_world B(n);
    string command;
    cin.get();
    while (getline(cin, command) && command != "quit") {
        vector<string> _command = translate(command);
        int a = stoi(_command[1]), b = stoi(_command[3]);
        if (B.pos[a] == B.pos[b]) {
            continue;
        }
        if (_command[0] == "move") {
            if (_command[2] == "onto") {
                B.op1(a, b);
            } else {
                B.op2(a, b);
            }
        } else {
            if (_command[2] == "onto") {
                B.op3(a, b);
            } else {
                B.op4(a, b);
            }
        }
    }
    B.print();
}
