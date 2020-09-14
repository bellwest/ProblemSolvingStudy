#include <iostream>
#include <vector>

using namespace std;

int T, N;
long long D;
vector<long long> v;

long long solution() {
    long long dn;
    
    v.clear();
    cin >> N >> D;
    v = vector<long long>(N, -1);
    
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
    
    dn = D;
    
    for (int i=N-1; i>=0; i--) {
        dn = (dn / v[i]) * v[i];
    }
    
    return dn;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": " << solution() << endl;
    }
    return 0;
}
