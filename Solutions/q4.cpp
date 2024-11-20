#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// Load answers from file
std::vector<std::string> loadAnswers(const std::string &filename) {
    std::vector<std::string> answers;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        answers.push_back(line);
    }
    return answers;
}
int main() {
    std::vector<std::string> answers = loadAnswers("answers.txt");
    if (answers.empty()) {
        std::cerr << "Error: No answers found in answers.txt" << std::endl;
        return 1;
    }
    std::string question;
    size_t index = 0;
    std::cout << "Type your question (or type 'exit' to quit):" << std::endl;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, question);
        if (question == "exit")
            break;

        // Output an answer and cycle through the list
        std::cout << answers[index] << std::endl;
        index = (index + 1) % answers.size();
    }
    return 0;
}
