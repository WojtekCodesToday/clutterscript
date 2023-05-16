#include "main/compile/compiler.cpp"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: cs <input_file1> [<input_file2> ...]" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        convertFile(argv[i]);
    }

    return 0;
}

