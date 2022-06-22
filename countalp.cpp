#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> m;
    for (int i = 0; i < n; i++) m[s[i]]++;

    for (int i = 0; i < alphabet.size(); i++) cout << alphabet[i] << " " << m[alphabet[i]] << '\n';
}
