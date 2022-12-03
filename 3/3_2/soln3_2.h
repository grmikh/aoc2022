#pragma once
#include <fstream>
#include <unordered_set>
#include <vector>

namespace soln32
{
    using namespace std;

    int getPriority(vector<string>&& rucksacks)
    {
        unordered_set<char> repeating;
        auto it = rucksacks.begin();
        copy(it->begin(), it->end(), inserter(repeating, repeating.begin()));
        while (++it != rucksacks.end())
        {
            auto part = partition(it->begin(), it->end(), [&repeating](char c){return repeating.contains(c);});
            repeating.clear();
            copy(it->begin(), part, inserter(repeating, repeating.begin()));
        }
        assert(repeating.size() == 1);
        return soln31::getPriority(*repeating.begin());
    }
}

int soln3_2(std::ifstream&& in)
{
    std::string rucksack;
    int sum = 0;
    int counter = 0;
    std::vector<std::string> rucksacks;
    while(in >> rucksack)
    {
        rucksacks.emplace_back(rucksack);
        ++counter;
        if (counter == 3)
        {
            sum += soln32::getPriority(std::move(rucksacks));
            rucksacks = {};
            counter = 0;
        }
    }
    return sum;
}
