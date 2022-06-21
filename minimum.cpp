#include <iostream>
using namespace std;
typedef long long ll;

const int INF = 2e9;

int findMin(int N, int A[]) {
    int res = INF;
    for (int i = 0; i < N; i++) res = min(res, A[i]);
    return res;
}