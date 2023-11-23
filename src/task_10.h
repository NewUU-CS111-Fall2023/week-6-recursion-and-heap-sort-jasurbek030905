#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string permuteString(const string &s) {
    vector<char> vowels;
    string result = s;

    for (char ch: s) {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' ||
            tolower(ch) == 'u') {
            vowels.push_back(ch);
        }
    }

    sort(vowels.begin(), vowels.end()); // Sort the vowels

    int vowelIndex = 0;
    for (char &ch: result) {
        if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' ||
            tolower(ch) == 'u') {
            ch = vowels[vowelIndex++];
        }
    }

    return result;
}

int main() {
    string inputString;
    getline(cin, inputString);
    string result = permuteString(inputString);
    cout << result << endl;
    return 0;
}
