#include <iostream>

using namespace std;

int reverseNumber(int n, int result = 0) {
    if (n == 0) {
        return result;
    } else
        return reverseNumber(n / 10, result * 10 + n % 10);
}

int main() {
    int num;
    cin >> num;
    int reversed = reverseNumber(num);
    cout << reversed << endl;
    return 0;
}
