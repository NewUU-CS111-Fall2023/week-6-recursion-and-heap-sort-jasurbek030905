#include <iostream>
using namespace std;
bool isPalindrome(const string& word, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (tolower(word[start]) != tolower(word[end])) {
        return false;
    }
    return isPalindrome(word, start + 1, end - 1);
}
int main() {
    string inputWord;
    getline(cin,inputWord);
    if (isPalindrome(inputWord, 0, inputWord.length() - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
