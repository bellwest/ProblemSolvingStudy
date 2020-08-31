#include <iostream>
#include <vector>

using namespace std;

int T, N, K, P;

int solution() {
    cin >> N >> K >> P;
    auto v = vector<vector<int>>(N, vector<int>(K, 0));
    int result = 0;
    for (int i=0; i<N; i++) 
        for (int j=0; j<K; j++)
            cin >> v[i][j];
    auto idx = vector<int>(N, 0);
    for (int i=0; i<P; i++) {
        int pick = 0;
        int max_beauty = 0;
        for (int n=0; n<N; n++) {
            if(v[n][idx[n]] > max_beauty) {
                max_beauty = v[n][idx[n]];
                pick = n;
            }
        }
        result += max_beauty;
        idx[pick]++;
    }
    return result;
}

int main() {
    cin >> T;
    for (int i=0; i<T; i++) {
        cout
        << "Case #"
        << i+1
        << ": "
        << solution()
        << endl;
    }
}
