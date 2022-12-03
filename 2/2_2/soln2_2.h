#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cassert>


namespace soln22
{
    using namespace std;
    int getPoints(char them, char res) {
        static unordered_map<char, short> results{{'X', 0},
                                                  {'Y', 3},
                                                  {'Z', 6}};
        static unordered_map<char, short> draw{{'A', 1},
                                               {'B', 2},
                                               {'C', 3}};
        static unordered_map<char, short> win{{'A', 2},
                                              {'B', 3},
                                              {'C', 1}};
        static unordered_map<char, short> lose{{'A', 3},
                                               {'B', 1},
                                               {'C', 2}};
        short pts = 0;
        switch (res) {
            case 'X':
                pts = lose[them];
                break;
            case 'Y':
                pts = draw[them];
                break;
            case 'Z':
                pts = win[them];
                break;
            default:
                throw invalid_argument("Unknown val");
        }
        return results[res] + pts;
    }
}
int soln2_2(std::ifstream&& in)
{
    char them, res;
    int total = 0;
    while(in >> them >> res)
    {
        total += soln22::getPoints(them ,res);
    }
    return total;
}

