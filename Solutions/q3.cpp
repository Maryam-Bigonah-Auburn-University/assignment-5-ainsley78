#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeFiles(const string& file1, const string& file2, const string& outputFile) {
    ifstream inFile1(file1), inFile2(file2);
    ofstream outFile(outputFile);
    vector<int> numbers;
    int num;

    // Read numbers from file1
    while (inFile1 >> num) numbers.push_back(num);
    // Read numbers from file2
    while (inFile2 >> num) numbers.push_back(num);

    // Sort and write to output file
    sort(numbers.begin(), numbers.end());
    for (int n : numbers) outFile << n << endl;

    inFile1.close();
    inFile2.close();
    outFile.close();
}

int main() {
    string file1 = "file1.txt";
    string file2 = "file2.txt";
    string outputFile = "file3.txt";

    mergeFiles(file1, file2, outputFile);
    cout << "Files merged into " << outputFile << endl;
    return 0;
}

