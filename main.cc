#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void TrimWhitespace(string& line) {
    for (size_t i = 0; i < line.size(); ++i) {
        if (isspace(line.at(i)) == 0) {
            line = line.substr(i);
            break;
        }
    }

    for (int i = line.size() - 1; i >= 0; --i) {
        if (isspace(line.at(i)) == 0) {
            line = line.substr(0, i + 1);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    ifstream input("input.txt");
    string line;
    int margin = 100;
    while (getline(input, line)) {
        TrimWhitespace(line);
        if (line.size() >= margin) {
            cout << line << endl;
        } else {
            for (int i = 0; i < (margin - line.size()); ++i) {
                cout << ' ';
            }
            cout << line << endl;
        }
    }
    return 0;
}