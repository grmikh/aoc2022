#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <deque>
#include <vector>
#include <unordered_set>


std::string soln5_1(std::ifstream&& in)
{
    static const std::unordered_set<char> special_chars = {'[', ']', ' ', '\r'};
    std::string str;
    std::vector<std::deque<char>> stacks;
    std::vector<std::array<int, 3>> commands;
    in >> std::noskipws;
    bool parsing_commands = false;
    while(getline(in, str, '\n'))
    {
        if (str == "\r")
        {
            for (auto& stack : stacks)
                stack.pop_back();
            parsing_commands = true;
            continue;
        }
        if (!parsing_commands)
        {
            int stack_idx = 0;
            int steps_advanced = 0;
            for (auto it = str.begin(); it != str.end(); it++, steps_advanced++)
            {
                if (stacks.size() <= stack_idx)
                    stacks.emplace_back();
                if (steps_advanced == 4)
                {
                    steps_advanced = 0;
                    stack_idx++;
                }
                if (special_chars.find(*it) != special_chars.end())
                    continue;
                stacks[stack_idx].push_back(*it);
            }
        } else
        {
            std::array<int, 3> command{};
            auto it = str.begin();
            int idx = 0;
            int commandidx = 0;
            do
            {
                const auto begin = it;
                while (*it != ' ' && it != str.end())
                    it++;
                if (idx == 1 || idx == 3 || idx == 5) {
                    command[commandidx] = std::stoi(std::string(begin, it));
                    commandidx++;
                }
                idx++;
            } while (it++ != str.end());
            commands.push_back(command);
        }
    }
    for (const auto& command : commands)
    {
        for (int i = 0; i < command[0]; i++)
        {
            auto elem = stacks[command[1] - 1].front();
            stacks[command[1] - 1].pop_front();
            stacks[command[2] - 1].push_back(elem);
        }
    }
    std::string out;
    for (const auto& stack : stacks)
        out += stack.front();
    return out;
}