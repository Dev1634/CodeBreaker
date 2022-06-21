#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    if (n >= 91) {
        cout << "A*\n";
    } else if (75 <= n && n <= 90) {
        cout << "A\n";
    } else if (60 <= n && n <= 74) {
        cout << "B\n";
    } else if (50 <= n && n <= 59) {
        cout << "C\n";
    } else if (35 <= n && n <= 49) {
        cout << "D\n";
    } else if (20 <= n && n <= 34) {
        cout << "E\n";
    } else {
        cout << "U\n";
    }
}
