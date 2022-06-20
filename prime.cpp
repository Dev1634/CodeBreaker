#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int n;

int main(){
    cin >> n;
    if(n <= 1) {
        cout << "Not Prime\n";
        return 0;
    }
    for(int i=2;i<=sqrt(n);i++){
        if(n%i == 0){
            cout << "Not Prime\n";
            return 0;
        }
    }
    cout << "Prime\n";
}
