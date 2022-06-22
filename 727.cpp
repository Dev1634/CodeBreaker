#include <iostream>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n, ind, i , cnt;
string s;
char ch;
iii ans;

int main(){
    // Subtask 2
    cin >> n >> s;

    while(ind < n) {
        ch = s[ind];
        if(ch == '7') {

            i = ind;
            cnt = 0;
            while(i < n && s[i + 1] == '2' && s[i + 2] == '7') {
                i += 2;
                cnt++;
            }
            if(cnt > ans.se) {
                ans.fi = ii(ind, i);
                ans.se = cnt;
            }
            ind = i;
        }
        ind++;
    }

    cout << ++ans.fi.fi << " " << ++ans.fi.se << endl;
}
