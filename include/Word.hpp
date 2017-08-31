#ifndef WORD_HPP
#define WORD_HPP

#include <string>

class Word
{
public:
    Word(std::string w, short i);
    virtual ~Word();

    std::string word;
    short index;

protected:

private:
};

#endif // WORD_HPP
