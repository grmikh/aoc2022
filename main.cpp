#include <iostream>
#include "2/2_1/soln2_1.h"
#include "2/2_2/soln2_2.h"
#include "3/3_1/soln3_1.h"
#include "3/3_2/soln3_2.h"
#include "4/4_1/soln4_1.h"
#include "4/4_2/soln4_2.h"
#include "5/5_2/soln5_2.h"

std::ifstream checked(std::ifstream&& in)
{
    assert(in.is_open());
    return std::move(in);
}
#define SOLN(problem_id) soln ## problem_id(checked(std::ifstream(#problem_id ".txt")))

int main()
{
    std::cout << SOLN(5_2) << std::endl;
}