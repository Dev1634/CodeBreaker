// #include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

inline long long readint() {
	long long x = 0;
	char ch = getchar_unlocked();
	while (ch < '0' || ch > '9')
		ch = getchar_unlocked();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar_unlocked();
	}
	return x;
}

inline void print(int x){
	if(x > 9)print(x / 10);
	putchar(x % 10 + '0');
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int q = readint();
	ll query;
	for (int x = 0; x < q; x++){
		query = readint();
        query++;
		
		int ans = 64 - __builtin_clzll(query);

		print(ans);
		putchar(' ');
	}
}
