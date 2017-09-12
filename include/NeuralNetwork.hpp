#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include "FileManager.hpp"
#include "MainNode.hpp"
#include "Node.hpp"
#include "FileManager.hpp"
#include "Word.hpp"
#include "DataAnalyser.hpp"

#include <vector>
#include <string>
#include <thread>
#include <iostream>
#include <ctime>
#include <random>
#include <mutex>

class NeuralNetwork
{
public:
    NeuralNetwork();
    virtual ~NeuralNetwork();

    void Start();

    void GenerateSubNodes(unsigned int s, unsigned int e);

protected:


private:
    std::vector<Word> wordList;
    std::vector<MainNode> nodeMap;

    std::mutex Mutex;

    FileManager fManager;
    DataAnalyser dAnalyser;

    bool InputMenu();
    void GenerateNodes();

    void TakeData();
    std::vector<std::string> GenerateSentence();
    void GenerateSentences();
    void SentenceInput(std::vector<std::string> &sentence);
};

#endif // NEURALNETWORK_HPP
