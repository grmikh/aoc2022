#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cassert>

namespace soln21
{
    using namespace std;
    static int getPoints(char them, char us) {
        static unordered_map<char, short> pts{{'X', 1},
                                              {'Y', 2},
                                              {'Z', 3}};
        static unordered_map<char, char> draw{{'X', 'A'},
                                              {'Y', 'B'},
                                              {'Z', 'C'}};
        static unordered_map<char, char> win{{'X', 'C'},
                                             {'Y', 'A'},
                                             {'Z', 'B'}};
        bool isdraw = draw[us] == them;
        bool iswin = win[us] == them;
        return pts[us] + 6 * iswin + 3 * isdraw;
    }
}
int soln2_1(std::ifstream &&in) {
    char them, us;
    int total = 0;
    while (in >> them >> us) {
        total += soln21::getPoints(them, us);
    }
    return total;
}
