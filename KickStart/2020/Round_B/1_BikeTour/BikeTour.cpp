#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> v;

int solution() {
    cin >> N;
    v.clear();
    v = vector<int>(N, -1);
    for (int i=0; i<N; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i=1; i<N-1; i++) {
        if (v[i] > v[i-1] && v[i] > v[i+1])
            ans++;
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
