#include "flappyrabbit.h"
#include <vector>
using namespace std;

vector<int> low, up;

void init(vector<int> A, vector<int> B) {
	low = A, up = B;
	int cur_max = A[0], cur_min = B[B.size() - 1];

	for (int i = 1; i < A.size(); i++) {
		cur_max = max(cur_max, A[i]);
		cur_min = min(cur_min, B[B.size() - i - 1]);
		low[i] = cur_max;
		up[B.size() - i - 1] = cur_min;
	}
}

int min_fuel(int L, int R) {
	return max(0, low[R] - up[L]);
}
