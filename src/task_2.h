#include <iostream>

using namespace std;

int recursion(int A) {
    if (A == 1) {
        cout << "YES";
    } else if (A % 2 == 1) {
        cout << "NO";
    }
    if (A % 2 == 0) {
        return recursion(A / 2);
    }
}


int main() {
    int n;
    cin >> n;
    recursion(n);
}


