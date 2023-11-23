#include <iostream>

using namespace std;

int recursion(int A) {
    if (A == 0) return 0;
    return recursion(A / 10) + A % 10;
}

int main() {
    int n;
    cin >> n;
    cout << recursion(n);
}

