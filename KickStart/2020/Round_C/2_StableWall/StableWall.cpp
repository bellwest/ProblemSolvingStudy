#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int T, R, C;

char wall[30][30];
bool build[30][30];
int alphabets[26]; // -1 means the alphabet is not found yet
// 0 means it's not added yet
// 1 means it's added

void printMap() {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << wall[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
void printBuild(bool b[30][30]) {
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

bool checkBuildStability(char c) {
    bool tempbuild[30][30];
    memcpy(tempbuild, build, sizeof(tempbuild));
//    cout << "checkBuildStability" << endl;
//    cout << "initial build" << endl;
//    printBuild(build);
//    cout << "initial tempbuild" << endl;
//    printBuild(tempbuild);

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (wall[i][j] == c) {
                tempbuild[i][j] = true;
            }
        }
    }
//    cout << "tempbuild after new build" << endl;
//    printBuild(tempbuild);
    for (int i=1; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (tempbuild[i-1][j] == true && tempbuild[i][j] == false ) {
                return false;
            }
        }
    }
    memcpy(build, tempbuild, sizeof(build));
    return true;
}


string solution() {
    cin >> R >> C;
    string ans = "";
    memset(alphabets, 0, sizeof(alphabets));
    memset(wall, 0, sizeof(wall));
    memset(build, false, sizeof(build));
    
    for (int i=0; i<R; i++) {
        cin >> wall[i];
    }

//    printMap();

    for (int i=0; i<R; i++) {
        bool updated = false;
        for (int j=0; j<C; j++)  {
            char c = wall[i][j];
            int cidx = (int)(c - 'A');
            if (alphabets[cidx] == 1) {
                continue; // alphabet already added
            } else if (alphabets[cidx] == -1) {
                alphabets[cidx] = 0; // alphabet found
            }
            
            if (alphabets[cidx] == 0) {
                if (checkBuildStability(c)) {
//                    printBuild(build);
                    updated = true;
                    alphabets[cidx] = 1;
                    ans += c;
//                    cout << c << " added, ans : " << ans << endl;
                }
            }
        }

        bool cleared = true;
        for (int k=0; k<C; k++) {
            if (!build[i][k]) {
                cleared = false;
                break;
            }
        }
        if (!cleared) { // if the current row is not built completely,
            if (!updated) return ""; // and if nothing is updated, this is impossible
            else i--; // if ith row is not built completely, try again
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int i=0; i<T; i++) {
        string ans = solution();
        if (ans == "") ans = "-1";
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}
