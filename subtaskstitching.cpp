#include<iostream>
#include<time.h>
using namespace std;

int main() {
    srand(clock());
    cout << rand() % 2 + 1;
}