#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

string replaceFourLetterWords(const string& input) {
    stringstream ss(input), result;
    string word;

    while (ss >> word) {
        if (word.length() == 4) { // Check if word length is 4
            if (isupper(word[0])) // Check if first letter is uppercase
                result << "Love ";
            else
                result << "love ";
        } else {
            result << word << " ";
        }
    }

    string output = result.str();
    return output.substr(0, output.length() - 1); // Remove trailing space
}

int main() {
    string input;
    cout << "Enter a line of text: ";
    getline(cin, input);

    string modified = replaceFourLetterWords(input);
    cout << "Modified Line: " << modified << endl;
    return 0;
}

