#include <iostream>
#include <vector>

using namespace std;

int T, N, K;
int M_MAX = 1000000000;

int solve() {
    int prev, curr, k_sum;
    int lo = 1, hi = M_MAX, d_opt = lo;
    vector<int> d_arr;

    cin >> N >> K;
    cin >> prev;

    for (int i=0; i<N-1; i++) {
        cin >> curr;
        d_arr.push_back(curr - prev);
        prev = curr;
    }
    
    while (lo < hi) {
        k_sum = 0;
        for (int i=0; i<N-1; i++) {
            k_sum += ((d_arr[i] / d_opt) + (d_arr[i] % d_opt == 0 ? 0 : 1) - 1);
        }
        if (k_sum > K) {
            lo = d_opt + 1;
        } else {
            hi = d_opt;
        }
        d_opt = (lo + hi) / 2;
    }
    
    return d_opt;
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 <<": " << solve() << endl;
    }
    return 0;
}
