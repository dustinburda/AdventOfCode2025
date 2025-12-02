#include <iostream>
#include <fstream>
#include <filesystem>

int solve_problem_one() {
    std::ifstream input_file (std::filesystem::current_path().parent_path() / "input_files/problem1.txt");

    std::string line;

    int start = 50;
    int num_times_zero = 0;
    while(std::getline(input_file, line)) {
        int sign = 1;
        if (line[0] == 'L')
            sign = -1;

        int rotation_count = std::stoi(line.substr(1, line.size() - 1));
        start = (start + sign * rotation_count);
        if (start < 0)
            start += 100;

        start %= 100;

        if (start == 0)
            num_times_zero++;
    }

    return num_times_zero;
}

int main() {
    int answer_problem_one = solve_problem_one();

}
