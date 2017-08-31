#ifndef DATAANALYSER_HPP
#define DATAANALYSER_HPP

#include <string>
#include <vector>
#include <cctype>

#include "Word.hpp"
#include "MainNode.hpp"


class DataAnalyser
{
public:
    DataAnalyser();
    virtual ~DataAnalyser();

    void AddData(std::vector<std::string> & trainingData, std::vector<MainNode> & nodeMap, std::vector<Word> & wordList);

protected:

private:
    std::string FindWord(std::string & s);
};

#endif // DATAANALYSER_HPP
