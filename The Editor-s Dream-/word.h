#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/** structure to define a word **/
struct Word
{
    string word;
    int count;
    vector<int> lineNumbers;

    //helper functions for comparison
    bool operator<(const Word &w) const { return word < w.word; }
    bool operator<=(const Word &w) const { return word <= w.word; }
    bool operator>(const Word &w) const { return word > w.word; }
    bool operator>=(const Word &w) const { return word >= w.word; }
    bool operator==(const Word &w) const { return word == w.word; }
    bool operator!=(const Word &w) const { return word != w.word; }

    Word operator=(const Word &w)
    {
        if (*this != w)
        {
            word = w.word;
            count = w.count;
            lineNumbers = w.lineNumbers;
        }

        return *this;
    }
};

/*
ostream& operator<<(ostream &out, const Word &w)
{
    out << w.word << " " << w.count << " ";
    out << ", " << w.lineNumbers[0];
    for (unsigned i = 1; i < w.lineNumbers.size(); i++)
        out << ", " << w.lineNumbers[i];
    return out;
}*/

#endif // word_h

