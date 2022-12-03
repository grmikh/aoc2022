#pragma once
#include <fstream>
#include <unordered_set>

namespace soln31
{
    using namespace std;
    int getPriority(char c)
    {
        int i = int(c);
        if (i >= 97)
            return i - 96;
        return i - 38;
    }

    int getPriority(string_view rucksack)
    {
        auto middle = rucksack.length() / 2;
        auto left = rucksack.substr(0, middle);
        auto right = rucksack.substr(middle, rucksack.length());
        unordered_set<char> leftChars;
        copy(left.begin(), left.end(), inserter(leftChars, leftChars.begin()));
        for (char c : right)
        {
            if (leftChars.contains(c))
            {
                return getPriority(c);
            }
        }
        throw invalid_argument("Couldn't find repeating character");
    }
}

int soln3_1(std::ifstream&& in)
{
    std::string rucksack;
    int sum = 0;
    while(in >> rucksack)
    {
        sum += soln31::getPriority(rucksack);
    }
    return sum;
}
