#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll t, a, b, k;
    cin >> t;
    for(ll i=0;i<t;i++){
        cin >> a >> b >> k;
        int x = a/k, y = b/k;
        if(x==y){
            cout << "Oolimry\n";
        }else{
            cout << "Errorgorn\n";
        }
    }
}
