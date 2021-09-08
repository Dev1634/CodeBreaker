#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, e, sum=0;
    cin >> n;
    for(ll i=0;i<n;i++){
        cin >> e;
        sum += e;
    }
    cout << sum << endl;
}