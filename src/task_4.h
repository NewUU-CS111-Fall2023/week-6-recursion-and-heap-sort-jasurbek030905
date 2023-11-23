#include <iostream>
using namespace std;
string Prime(int n, int i=2) {
    if (n <= 2) {
        return (n == 2) ? "YES" : "NO";
    }
    if (n % i == 0) {
        return "NO";
    }
    if (i * i > n) {
        return "YES";
    }
    return Prime(n, i + 1);
}

int main() {
    int num ;
    cin>>num;
    cout << Prime(num) << endl;
    return 0;
}
