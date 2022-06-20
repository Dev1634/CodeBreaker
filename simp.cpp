#include <iostream>
using namespace std;
typedef long long ll;

int n;
int a[2];
int b[2];
int c[2];

int main(){
    cin >> n;
    string ans = "YES\n";
    for(int i : {0, 1}) cin >> a[i]; // Kai
    for(int i : {0, 1}) cin >> b[i]; // Pavement
    for(int i : {0, 1}) cin >> c[i]; // c1 c2
    if( a[0] == b[0] || a[1] == b[1] || a[0] == c[0] || a[1] == c[1] ) ans = "NO\n";
    else if( (b[0] > a[0] && c[0] < a[0]) || (b[0] < a[0] && c[0] > a[0]) ) ans = "NO\n";
    else if( (b[1] > a[1] && c[1] < a[1]) || (b[1] < a[1] && c[1] > a[1]) ) ans = "NO\n";
    cout << ans;
}
