#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
typedef long long ll;

int main() {
    int tri[27][27];
    memset(tri, 0, sizeof(tri));

    tri[1][1] = 1;
    
    for (int i = 2; i < 26; i++) {
        tri[i][1] = 1;
        for (int j = 2; j < i; j++) {
            tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
        tri[i][i] = 1;
    }

    int r, c; cin >> r >> c;
    cout << tri[r][c] << '\n';
}
