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

void Usage(char* prog) {
    cout << "Usage: " << prog << " <margin> [input_file]" << endl;
    cout << "<margin> is required. [input_file] is optional. If [input_file] unspecfied, default is standard input." << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        Usage(argv[0]);
        return 1;
    }

    int margin = atoi(argv[1]);
    if (margin == 0) {
        cerr << "Failed to convert margin to non-zero number: " << argv[1] << endl;
        Usage(argv[0]);
        return 1;
    }

    istream* input;
    ifstream file_stream;
    if (argc == 3) {
        file_stream.open(argv[2]);
        if (!file_stream.good()) {
            cerr << "Could not open input file: " << argv[2] << endl;
            Usage(argv[0]);
            return 1;
        }
        input = &file_stream;
    } else {
        input = &cin;
    }

    string line;
    while (getline(*input, line)) {
        TrimWhitespace(line);
        if (line.size() == 0) {
            cout << endl;
        } else if (line.size() >= margin) {
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