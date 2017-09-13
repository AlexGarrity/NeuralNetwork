#include "DataAnalyser.hpp"

DataAnalyser::DataAnalyser()
{
    //ctor
}

DataAnalyser::~DataAnalyser()
{
    //dtor
}

std::string DataAnalyser::FindWord(std::string & sentence)
{
    bool fullWord = false;
    std::string word;
    unsigned short counter = 0;
    while (fullWord != true && counter <= sentence.size())
    {
        if (std::isspace(sentence.at(counter)) == false)
        {
            word.push_back(sentence.at(counter));
        }
        else
        {
            fullWord = true;
            sentence.erase(sentence.begin(), sentence.begin() + counter + 1);
        }
        counter ++;
    }
    return word;
}

void DataAnalyser::AddData(std::vector<std::string> & trainingData, std::vector<MainNode> & nodeMap, std::vector<Word> & wordList)
{
    short prevWordIndex = 0;
    short wordIndex = 0;
    for (unsigned int i = 1; i < trainingData.size(); i++)
    {
        for (unsigned int j = 0; j < wordList.size(); j++)
        {
            if (wordList[j].word == trainingData[i-1])
            {
                prevWordIndex = j;
                break;
            }
        }
        for (unsigned int j = 0; j < wordList.size(); j++)
        {
            if (wordList[j].word == trainingData[i])
            {
                wordIndex = j;
                break;
            }
        }
        nodeMap[prevWordIndex].IncreaseWeight(wordIndex);
    }
}


void DataAnalyser::RemoveData(std::vector<std::string> & trainingData, std::vector<MainNode> & nodeMap, std::vector<Word> & wordList)
{
    short prevWordIndex = 0;
    short wordIndex = 0;
    for (unsigned int i = 1; i < trainingData.size(); i++)
    {
        for (unsigned int j = 0; j < wordList.size(); j++)
        {
            if (wordList[j].word == trainingData[i-1])
            {
                prevWordIndex = j;
                break;
            }
        }
        for (unsigned int j = 0; j < wordList.size(); j++)
        {
            if (wordList[j].word == trainingData[i])
            {
                wordIndex = j;
                break;
            }
        }
        nodeMap[prevWordIndex].DecreaseWeight(wordIndex);
    }
}
