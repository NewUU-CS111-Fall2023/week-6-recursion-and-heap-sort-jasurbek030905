#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(const string &num1, const string &num2) {
    int carry = 0;
    string result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += num2[j] - '0';
            j--;
        }
        carry = sum / 10;
        sum = sum % 10;
        result += (sum + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
string subtract(const string &num1, const string &num2) {
    string result;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int borrow = 0;
    while (i >= 0 || j >= 0) {
        int diff = (i >= 0 ? (num1[i] - '0') : 0) - (j >= 0 ? (num2[j] - '0') : 0) - borrow;
        borrow = 0;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        result += (diff + '0');
        i--;
        j--;
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();  // Remove leading zeros
    }
    reverse(result.begin(), result.end());
    return result;
}
string karatsubaMultiply(const string &X, const string &Y) {
    int n = max(X.size(), Y.size());
    if (n <= 1) {
        int result = stoi(X) * stoi(Y);
        return to_string(result);
    }
    int m = n / 2;
    string Xl = X.substr(0, n - m);
    string Xr = X.substr(n - m, m);
    string Yl = Y.substr(0, n - m);
    string Yr = Y.substr(n - m, m);
    string P1 = karatsubaMultiply(Xl, Yl);
    string P2 = karatsubaMultiply(Xr, Yr);
    string P3 = karatsubaMultiply(add(Xl, Xr), add(Yl, Yr));
    P3 = subtract(P3, add(P1, P2));
    for (int i = 0; i < 2 * m; i++) {
        P1 += '0';
    }
    for (int i = 0; i < m; i++) {
        P3 += '0';
    }

    string result = add(add(P1, P3), P2);
    return result;
}

int main() {
    string num1, num2;
    cin >> num1;
    cin >> num2;

    string result = karatsubaMultiply(num1, num2);
    cout << result << endl;

    return 0;
}
