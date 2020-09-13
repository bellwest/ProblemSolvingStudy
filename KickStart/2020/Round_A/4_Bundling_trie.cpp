#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

#define ALPHABETS 26

int T, N, K;
int score;

struct TrieNode {
    int children[ALPHABETS];
    int cnt;
    TrieNode() : cnt(0) {
        memset(children, -1, sizeof(children));
    }
};

vector<TrieNode> trie;

int addNewNodeAndReturnIdx() {
    TrieNode node;
    trie.push_back(node);
    return trie.size() - 1;
}

void insert(int n, const string& str, int i) {
    // WARNING: Do not do this like below
    //
    // TrieNode& node = trie[n];
    // ... node.children[i] ...
    //
    // trie[n] and node might not return the same address
    // needs experiments..
    if (i == str.length()) {
        trie[n].cnt++;
        return;
    }

    int idx = str[i] - 'A';
    if (trie[n].children[idx] == -1) {
        int next = addNewNodeAndReturnIdx();
        trie[n].children[idx] = next;
        // WARNING: Do not do this like below:
        // 
        // trie[n].children[idx] = addNewNodeAndReturnIdx();
        // 
        // don't know the exact reason for now
        // addNewNodeAndReturnIdx() mutates trie and assignment itself as well
        // it might cause the issue
        // runs well in mac, though..
    }

    insert(trie[n].children[idx], str, i + 1);
}

int dfs(int n, int len) { // returns remaining
    for (int i = 0; i < ALPHABETS; i++) {
        int childIdx = trie[n].children[i];
        if (childIdx != -1) {
            trie[n].cnt += dfs(childIdx, len + 1);
        }
    }
    score += (trie[n].cnt / K) * len;
    return trie[n].cnt % K;
}

int solve() {
    trie.clear();
    addNewNodeAndReturnIdx();
    score = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        insert(0, str, 0);
    }
    dfs(0, 0);
    return score;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int result = solve();
        cout << "Case #" << i + 1 << ": " << result << endl;
    }
    return 0;
}
