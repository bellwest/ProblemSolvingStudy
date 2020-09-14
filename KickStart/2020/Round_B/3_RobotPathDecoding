#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define GSIZE 1000000000

int T;
long long w, h, factor;

void maneuver(char c) {
    switch (c) {
        case 'S':
            h = ((h + factor) % GSIZE);
            return;
        case 'N':
            h = ((h + GSIZE - factor) % GSIZE);
            return;
        case 'E':
            w = ((w + factor) % GSIZE);
            return;
        case 'W':
            w = ((w + GSIZE - factor) % GSIZE);
            return;
    }
}

void solve() {
    w = h = 0;
    factor = 1;
    stack<long long> s;
    s.push(1);
    string program;
    cin >> program;
    
    for (char c : program) {
        if (c >= '2' && c <= '9') {
            s.push((factor * (int)(c - '0')) % GSIZE); // two mutation to s in a single line. problematic?
            factor = s.top();
        } else if (c == '(') {
            continue;
        } else if (c == ')') {
            s.pop();
            factor = s.top();
        } else {
            maneuver(c);
        }
    }
    w++; h++;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i=0; i<T; i++) {
        solve();
        cout << "Case #" << i+1 << ": " << w << " " << h << endl;
    }
    return 0;
}
