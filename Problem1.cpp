#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int mod(int a, int b) {
    int mod = a % b;
    if (mod < 0)
        mod += b;

    return mod;
}

int solve_problem_one(std::string filename) {
    std::ifstream input_file (std::filesystem::current_path().parent_path() / ("input_files/" + filename + ".txt"));

    std::string line;

    int current_dial_val = 50;
    int num_times_zero = 0;
    while(std::getline(input_file, line)) {

        int rotation_count = (line[0] == 'L' ? -1 : 1) * std::stoi(line.substr(1, line.size() - 1));

        current_dial_val = mod(current_dial_val + rotation_count, 100);

        if (current_dial_val == 0)
            num_times_zero++;
    }

    return num_times_zero;
}

int num_times_past_zero(int prev_dial_val, int current_dial_val){
    int num_times_pass_zero = 0;
    if (current_dial_val < 0) {
        if (prev_dial_val != 0)
            num_times_pass_zero = std::abs(current_dial_val / 100) + 1;
        else
            num_times_pass_zero = std::abs(current_dial_val / 100);
    } else if (current_dial_val == 0) {
        num_times_pass_zero = std::abs(current_dial_val / 100) + 1;
    } else if(current_dial_val >= 100) {
        num_times_pass_zero = std::abs(current_dial_val / 100);
    }

    return num_times_pass_zero;
}

int solve_problem_two(std::string filename) {
    std::ifstream input_file (std::filesystem::current_path().parent_path() / ("input_files/" + filename + ".txt"));

    std::string line;

    int current_dial_val = 50;
    int num_times_pass_zero = 0;
    while(std::getline(input_file, line)) {
        int rotation_count = (line[0] == 'L' ? -1 : 1) * std::stoi(line.substr(1, line.size() - 1));

        num_times_pass_zero += num_times_past_zero(current_dial_val, current_dial_val + rotation_count);

        current_dial_val = mod(current_dial_val + rotation_count, 100);
    }

    return num_times_pass_zero;
}