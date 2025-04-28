#include <bits/stdc++.h>
using namespace std;

int main() {
    string filename;
    cin >> filename;

    ifstream newfile(filename);
    if (!newfile.is_open()) {
        cerr << "Could not open file\n";
        return -1;
    }

    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(newfile, line)) {
        lineCount++;
        for (char e : line) {
            if (e != ' ') charCount++;
        }
        istringstream iss(line);
        string word;
        while (iss >> word) wordCount++;
    }

    newfile.close();

    cout << "Chars: " << charCount << '\n';
    cout << "Words: " << wordCount << '\n';
    cout << "Lines: " << lineCount << '\n';
    
    return 0;
}