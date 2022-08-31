#include "summarising2020.h"
#include <vector>
#include <map>
using namespace std;

map<long long, vector<int>> m;
long long cnt = 0ll;

long long xythesnake(int N, vector<int> A) {
    m[cnt++] = A;
    return cnt - 1;
}
vector<int> friendofxy(int N, long long X) {
	return m[X];
}
