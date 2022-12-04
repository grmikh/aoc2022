#pragma once
#include <iostream>
#include <fstream>

namespace soln41
{
    using namespace std;
    struct Range
    {
        unsigned int bgn;
        unsigned int end;
        bool contains(const Range& other) const
        {
            return bgn <= other.bgn && end >= other.end;
        }

        explicit Range(const string& sw)
        {
            auto idx = sw.find('-');
            bgn = stoi(sw.substr(0, idx), nullptr, 10);
            end = stoi(sw.substr(idx + 1, sw.size() - idx), nullptr, 10);
        }
    };
    class RangeParser {
    public:
        pair<Range, Range> operator()() const {
            return make_pair(Range(first), Range(second));
        }

    private:
        string first;
        string second;

        friend istream &operator>>(istream &is, RangeParser &rp) {
            string s;
            is >> s;
            auto idx = s.find(',');
            rp.first = s.substr(0, idx);
            rp.second = s.substr(idx + 1, s.size() - idx);
            return is;
        }
    };
}

int soln4_1(std::ifstream&& in)
{
    int count = 0;
    soln41::RangeParser rp;
    while(in >> rp)
    {
        auto pair = rp();
        if (pair.first.contains(pair.second) || pair.second.contains(pair.first))
            count++;
    }
    return count;
}