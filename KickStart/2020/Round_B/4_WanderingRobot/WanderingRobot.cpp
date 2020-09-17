#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define VSIZE 200100
int T, W, H, L, U, R, D;
vector<double> log2fact;

double solution() {
    double ans = 0.0;
    cin >> W >> H >> L >> U >> R >> D;
    
    if (D+1 <= H) {
        for (int x=L-1, y=D+1; x>=1; x--, y++) {
            ans += exp2(log2fact[x+y-2] - log2fact[x-1] - log2fact[y-1] - (x+y-2));
        }
    }
    
    if (R+1 <= W) {
        for (int x=R+1, y=U-1; y>=1; x++, y--) {
            ans += exp2(log2fact[x+y-2] - log2fact[x-1] - log2fact[y-1] - (x+y-2));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    
    log2fact = vector<double>(VSIZE, 0);
    
    for (int i=1; i<=VSIZE; i++) {
        log2fact[i] = log2fact[i-1] + log2(i);
    }
    
    cin >> T;
    for (int i=0; i<T; i++) {
        cout << "Case #" << i+1 << ": " << solution() << endl;
    }
    return 0;
}
