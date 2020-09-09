#include <iostream>
#include <vector>

using namespace std;

int T, N, K;
constexpr int ALPHABETS = 26;
int score;

struct TrieNode {
    vector<TrieNode*> children;
    int cnt;
    int len;
    
    int toInt(char c) {
        return (int)(c - 'A');
    }
    
    void insert(const string& str) {
        if (str == "") {
            cnt++;
            return;
        }
        int idx = toInt(str[0]);
        if (!children[idx])
            children[idx] = new TrieNode(len+1);
        children[idx]->insert(str.substr(1));
    }
    
    TrieNode(const int len): len(len), cnt(0) {
        children = *(new vector<TrieNode*>(ALPHABETS));
    }
    ~TrieNode() {
        for (int i=0; i<ALPHABETS; i++) {
            if (children[i]) delete children[i];
        }
    }
    int dfs() { // returns remaining
        for (int i=0; i<ALPHABETS; i++) {
            if (children[i]) {
                cnt += children[i]->dfs();
            }
        }
        score += (cnt / K) * len;
        return cnt % K;
    }
};

struct Trie {
    TrieNode* head;
    void insert(const string& str) {
        head->insert(str);
    }
    Trie() {
        head = new TrieNode(0);
    }
    ~Trie() {
        delete head;
    }
    void dfs() {
        head->dfs();
        return;
    }
};

int solve() {
    string str;
    Trie trie;
    score = 0;
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        cin >> str;
        trie.insert(str);
    }
    trie.dfs();
    return score;
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
