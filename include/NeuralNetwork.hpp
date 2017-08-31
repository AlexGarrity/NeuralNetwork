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

protected:


private:
    std::vector<Word> wordList;
    std::vector<MainNode> nodeMap;

    std::mutex Mutex;

    FileManager fManager;
    DataAnalyser dAnalyser;

    bool InputMenu();
    void GenerateNodes();
    void GenerateSubNodes(unsigned int s, unsigned int e);
    void TakeData();
    void GenerateSentence();
};

#endif // NEURALNETWORK_HPP
