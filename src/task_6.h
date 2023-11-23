#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num;
    while (true) {
        cin >> num;
        if (num == 0) {
            break;
        }
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[numbers.size() - 2];
    return 0;
}
