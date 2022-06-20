#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b>0) return gcd(b, a%b);
    else return a;
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
}