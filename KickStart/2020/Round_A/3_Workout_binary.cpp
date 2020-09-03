#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, N, K;

int solve() {
    int prev, curr;
    priority_queue<int> q;
    cin >> N >> K;
    cin >> prev;
    for (int i=0; i<N-1; i++) {
        cin >> curr;
        q.push(curr - prev);
        prev = curr;
    }
    
    for (int i=0; i<K; i++) {
        int max = q.top();
        q.pop();
        q.push(max/2);
        q.push(max - (max/2));
    }
    
    return q.top();
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 <<": " << solve() << endl;
    }
    return 0;
}
