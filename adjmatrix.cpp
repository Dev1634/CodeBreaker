#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
typedef long long ll;

int n, e, a, b;

int main(){
    cin >> n >> e;
    int graph[n][n];
    memset(graph, 0, sizeof(graph));
    for(int i=0;i<e;i++){
        cin >> a >> b;
        graph[--a][--b] = 1, graph[b][a] = 1;
    }
    for(int i=0;i<n;i++){
        for(int l=0;l<n;l++){
            cout << graph[i][l];
        }
        cout << "\n";
    }
}
