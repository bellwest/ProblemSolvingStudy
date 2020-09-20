#include <iostream>

using namespace std;

int T, N, K;

int solution() {
    cin >> N >> K;
    int ans = 0;
    int curr = 0;
    int expected = K;
    for (int i=0; i<N; i++) {
        cin >> curr;
        if (curr == expected) {
            if (expected == 1) {
                ans++;
                expected = K;
            } else {
                expected--;
            }
        } else {
            expected = K;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": " << solution() << endl;
    }
    return 0;
}
