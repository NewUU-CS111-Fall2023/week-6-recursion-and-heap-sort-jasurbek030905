#include <iostream>

using namespace std;

int recursion1(int A, int B) {
    if (A >= B) {
        cout << A << " ";
        return recursion1(A - 1, B);
    }
}

int recursion2(int A, int B) {
    if (A <= B) {
        cout << A << " ";
        return recursion2(A + 1, B);
    }
}

int main() {
    int A, B;
    cin >> A;
    cin >> B;
    if (A >= B) recursion1(A, B);
    else recursion2(A, B);
}

