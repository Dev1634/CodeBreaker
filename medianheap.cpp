#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> minh;
    priority_queue<int> maxh;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "PUSH") {
            int e; cin >> e;
            if (maxh.empty()) {
                maxh.push(e);
            } else {
                int mid = maxh.top();
                if (e < mid) maxh.push(e);
                else minh.push(e);
            }
        } else if (s == "POP") {
            if (maxh.size() >= minh.size()) maxh.pop();
            else minh.pop();
        }

        if (maxh.size() > minh.size() + 1) {
            minh.push(maxh.top());
            maxh.pop();
        } else if (minh.size() > maxh.size() + 1) {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    vector<int> v;
    while (!maxh.empty()) {
        v.push_back(maxh.top());
        maxh.pop();
    }
    while (!minh.empty()) {
        v.push_back(minh.top());
        minh.pop();
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << '\n';
}
