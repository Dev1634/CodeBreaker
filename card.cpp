#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Node {
    int val;
    struct Node *next;
};

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<Node> v(n);

    for (int i = 0; i < n - 1; i++) {
        v[i].val = i;
        v[i].next = &v[i + 1];
    }
    v[n - 1].val = n - 1;
    v[n - 1].next = NULL;

    Node *head = &v[0], *last = &v[n - 1];

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A') {
            last -> next = head;
            last = head;
            head = head -> next;
            last -> next = NULL;
        } else {
            last -> next = head -> next;
            last = head -> next;
            head -> next = head -> next -> next;
        }
    }

    Node *cur = head;
    for (int i = 0; i < k - 1; i++) cur = cur -> next;
    cout << cur -> val << " " << cur -> next -> val << " " << cur -> next -> next -> val << '\n';
}
