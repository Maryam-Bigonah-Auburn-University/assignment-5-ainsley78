#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

string correctSentence(const string& input) {
    stringstream result;
    bool capitalize = true;

    for (size_t i = 0; i < input.length(); i++) {
        if (isspace(input[i])) { // Compress spaces
            if (!isspace(input[i - 1])) result << ' ';
        } else {
            if (capitalize) { // Capitalize the first letter
                result << (char)toupper(input[i]);
                capitalize = false;
            } else { // Convert other letters to lowercase
                result << (char)tolower(input[i]);
            }
        }
    }
    return result.str();
}

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);

    string corrected = correctSentence(input);
    cout << "Corrected Sentence: " << corrected << endl;
    return 0;
}

