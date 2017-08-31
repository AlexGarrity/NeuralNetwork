#include "FileManager.hpp"

FileManager::FileManager()
{
    //ctor
}

FileManager::~FileManager()
{
    //dtor
}

void FileManager::LoadDictionary(std::vector<Word> & wordList, std::string filepath)
{
    std::ifstream fileReader(filepath.c_str(), std::ifstream::in);
    std::string temp;
    short counter = 0;
    while (fileReader)
    {
        fileReader >> temp;
        wordList.push_back(Word(temp, counter));
        counter++;
    }
    wordList.pop_back();
    fileReader.close();
}

void FileManager::LoadTrainingData(std::vector<std::string> & trainingData, std::string filepath)
{
    std::ifstream fileReader(filepath.c_str(), std::ifstream::in);
    std::string temp;
    while (fileReader)
    {
        fileReader >> temp;
        if (trainingData.size() > 1)
        {
            if (temp != trainingData[trainingData.size() - 2])
            {
                trainingData.push_back(temp);
            }
        }
        else
        {
            trainingData.push_back(temp);
        }
    }
    trainingData.pop_back();
    fileReader.close();
}
