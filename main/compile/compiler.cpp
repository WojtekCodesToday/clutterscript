#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void convertFile(const std::string& input_file_path) {
    std::ifstream input_file(input_file_path);
    if (!input_file) {
        std::cout << "Error: could not open file " << input_file_path << std::endl;
        return;
    }

    std::string output_file_name = input_file_path + ".js";
    std::ofstream output_file(output_file_name);
    if (!output_file) {
        std::cout << "Error: could not create file " << output_file_name << std::endl;
        return;
    }

    std::vector<std::string> keywords = {
        "let", "var", "const", "if", "else", "for", "while", "do", "switch", "case",
        "break", "continue", "return", "function", "class", "import"
    };

    std::vector<std::string> keywordsTwo = {
        "from", "+", "-", "/", "=", "*"
    };

    std::string line;
    while (std::getline(input_file, line)) {
        // Add space after keywords
        for (const std::string& keyword : keywords) {
            std::string search = keyword;
            std::string replace = keyword + " ";
            size_t pos = line.find(search);
            while (pos != std::string::npos) {
                // Check if there's already a space after the keyword
                if (line[pos + search.size()] != ' ') {
                    line.replace(pos, search.size(), replace);
                    pos += replace.size();
                }
                else {
                    pos += search.size() + 1;  // Skip the keyword and the existing space
                }
                pos = line.find(search, pos);
            }
        }

        // Add spaces before and after keywordsTwo
        for (const std::string& keyword : keywordsTwo) {
            std::string search = keyword;
            std::string replace = " " + keyword + " ";
            size_t pos = line.find(search);
            while (pos != std::string::npos) {
                line.replace(pos, search.size(), replace);
                pos = line.find(search, pos + replace.size());
            }
        }

        output_file << line << '\n';
    }

    input_file.close();
    output_file.close();

    std::cout << "Successfully converted the .cscript file to .js." << std::endl;
}
