#pragma once

#include <string>
#include <sstream>

class Leftpad {
 public:
    Leftpad(const int margin) : margin_(margin) { }

    ~Leftpad() = default;

    std::string Process(const std::string& input) {
        std::string output = input;
        TrimWhitespace(output);
        if ((output.size() == 0) || (output.size() >= margin_)) {
            return output;
        } else {
            std::stringstream stream;
            for (int i = 0; i < (margin_ - output.size()); ++i) {
                stream << ' ';
            }
            stream << output;
            return stream.str();
        }
    }

 private:
    int margin_ = 0;

    void TrimWhitespace(std::string& line) {
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
};
