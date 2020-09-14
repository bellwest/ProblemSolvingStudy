#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, B;
vector<int> A;

int solution() {
    cin >> N >> B;
    A = vector<int>(N, 0);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int res = 0;
    for (int i=0; i<A.size(); i++) {
        B -= A[i];
        if (B < 0) break;
        res++;
    }
    return res;
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << 
        "Case #" << 
        i+1 << 
        ": " << 
        solution() <<
        endl;
    }
    return 0;
}
