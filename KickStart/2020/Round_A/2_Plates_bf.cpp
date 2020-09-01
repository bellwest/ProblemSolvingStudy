#include <iostream>
#include <vector>

using namespace std;

int T, N, K, P;
vector<vector<int>> beautyMap;
int maxBeauty;

void pick(int n, int p, int beauty) {
    if (n == N-1) { // this is the last stack
        int pickHere = P - p;
        if (pickHere <= K) { // otherwise, not enough plates are left to pick
            maxBeauty = max(maxBeauty, beauty + beautyMap[n][pickHere-1]);
        }
        return;
    }
    
    for (int i=0; i<=K && i+p<=P; i++) { // i plates will be chosen in nth stack
        pick(n+1, p+i, beauty + beautyMap[n][i-1]);
    }
}

int maxFromBruteForce() {
    maxBeauty = -1;
    pick(0, 0, 0);
    return maxBeauty;
}

int solve() {
    cin >> N >> K >> P;
    beautyMap = vector<vector<int>>(N, vector<int>(K, -1));
    for (int i=0; i<N; i++) {
        for (int j=0; j<K; j++) {
            cin >> beautyMap[i][j];
            if (j !=0) beautyMap[i][j] += beautyMap[i][j-1];
        }
    }
    
    return maxFromBruteForce();
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        int res = solve();
        cout << "Case #" << i+1 << ": " << res << endl;
    }
    return 0;
}
