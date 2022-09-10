#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;

string digits[10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string tens[10] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

int main() {
    vector<int> primes;
    bool sieve[(int)2e6];
    memset(sieve, 1, sizeof(sieve));

    for (int i = 2; i < 2e6; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < 2e6; j += i) sieve[j] = 0;
        }
    }

    int n, m; cin >> n >> m;
    n = primes[n - 1];
    string ans = "";

    if (n / (int)1e6) { // 1,000,000
        ans += "one million ";
        n %= (int)1e6;
    }

    bool thousand = 0;
    if (n / (int)1e5) { // 100,000
        ans += digits[n / (int)1e5] + " hundred ";
        n %= (int)1e5;
        thousand = 1;
    }

    if (n / (int)1e4) {
        if (n / (int)1e4 == 1) {
            ans += teens[n / (int)1e3 % 10] + " ";
            thousand = 1;
            n %= (int)1e3;
        } else {
            ans += tens[n / (int)1e4] + " ";
            n %= (int)1e4;
            thousand = 1;
        }
    }

    if (n / (int)1e3) {
        ans += digits[n / (int)1e3] + " thousand ";
    } else if (thousand) {
        ans += "thousand ";
    }
    n %= (int)1e3;

    if (n / (int)1e2) { // 100
        ans += digits[n / (int)1e2] + " hundred ";
        n %= (int)1e2;
    }

    if (n / 10) { // 10
        if (n / 10 == 1) {
            ans += teens[n % 10] + " ";
            n %= 1;
        } else {
            ans += tens[n / 10] + " ";
            n %= 10;
        }
    }
    
    if (n) ans += digits[n] + " ";

    ans.pop_back();
    string dummy; getline(cin, dummy);
    for (int i = 0; i < m; i++) {
        string s; getline(cin, s);
        s[0] = tolower(s[0]);

        if (s == ans) cout << "Correct!\n";
        else cout << "Wrong!\n";
    }
}
