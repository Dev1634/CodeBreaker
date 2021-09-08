#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll moves = abs(x2-x1)+abs(y2-y1);
        if(x2!=x1 && y2!=y1){
            moves += 2;
        }
        cout << moves << endl;
    }
}