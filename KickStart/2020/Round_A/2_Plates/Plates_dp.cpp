#include <iostream>
#include <vector>

using namespace std;

int T, N, K, P;
vector<vector<int>> beautyMap;
vector<vector<int>> cache;

int maxFromDP() {
    cache = vector<vector<int>>(N, vector<int>(P+1, 0));
    for (int j=1; j<P+1; j++) {
        if (j <= K) cache[0][j] = beautyMap[0][j];
        else cache[0][j] = beautyMap[0][K];
    }
    
    for (int i=1; i<N; i++) {
        for (int j=1; j<P+1; j++) {
            for (int x=0; x<j+1 && x<K+1; x++) {
                cache[i][j] = max(cache[i][j], cache[i-1][j-x] + beautyMap[i][x]);
            }
        }
    }
    
    return cache[N-1][P];
}

int solve() {
    cin >> N >> K >> P;
    beautyMap = vector<vector<int>>(N, vector<int>(K+1, 0));
    for (int i=0; i<N; i++) {
        for (int j=1; j<K+1; j++) {
            cin >> beautyMap[i][j];
            if (j !=0) beautyMap[i][j] += beautyMap[i][j-1];
        }
    }
    
    return maxFromDP();
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        int res = solve();
        cout << "Case #" << i+1 << ": " << res << endl;
    }

    return 0;
}
