#include <cassert>
#include <iostream>

#include "Problem1.h"


int main() {
    assert(solve_problem_one("sample") == 3);
    assert(solve_problem_two("sample") == 6);

    int answer_problem_one = solve_problem_one("problem1");
    int answer_problem_two = solve_problem_two("problem1");

    std::cout << answer_problem_two << std::endl;

}
