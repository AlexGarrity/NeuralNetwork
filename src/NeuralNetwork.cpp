#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork()
{
    //ctor
}

NeuralNetwork::~NeuralNetwork()
{
    //dtor
}

void NeuralNetwork::GenerateNodes()
{
    short sum = 0;
    for (unsigned int i = 0; i < wordList.size(); i++)
    {
        nodeMap.push_back(MainNode(i));
        sum ++;
    }
}

void NeuralNetwork::GenerateSubNodes(unsigned int startPoint, unsigned int endPoint)
{
    if (endPoint > nodeMap.size() - 1) {
        endPoint = nodeMap.size() - 1;
        startPoint = 0;
    }
    //Mutex.lock();
    for (unsigned int i = startPoint; i < endPoint; i++)
    {
        nodeMap[i].GenerateSubNodes(wordList);
    }
    //Mutex.lock();
}

bool NeuralNetwork::InputMenu()
{
    std::string input;
    std::cout << "\nDo you wish to load test data from a file?" << std::endl;
    std::cin >> input;
    if ((input == "no") || (input == "n"))
    {
        return false;
    }
    std::cout << "Input not valid, defaulting to loading from file" << std::endl;
    return true;
}

void NeuralNetwork::GenerateSentence()
{
    short length = 0;
    short currentWord = 0;
    std::string sentence;
    std::cout << "\nGenerating a sentence..." << std::endl;
    sentence.append(wordList[currentWord].word);
    sentence.append(" ");
    char sentenceLength = rand() % 8 + 5;
    while (length < sentenceLength)
    {
        currentWord = nodeMap[currentWord].NextWord();
        if (currentWord != -1)
        {
            sentence.append(wordList[currentWord].word);
            sentence.append(" ");
            length ++;
        }
        else
        {
            std::cout << "No extra connections found, final result: " << std::endl;
            break;
        }
    }
    std::cout << sentence << std::endl;
}

void NeuralNetwork::Start()
{
    time_t startTime;
    time_t endTime;

    std::cout << "\nLoading dictionary..." << std::endl;
    time (&startTime);
    fManager.LoadDictionary(wordList, "./assets/words.txt");
    time (&endTime);
    std::cout << "Loaded " << wordList.size() << " words in " << difftime(endTime,startTime) << " seconds." << std::endl;

    std::cout << "\nGenerating nodes for " << wordList.size() << " words..." << std::endl;
    time(&startTime);
    GenerateNodes();
    time(&endTime);
    std::cout << "Generated " << nodeMap.size() << " nodes in " << difftime(endTime, startTime) << " seconds." << std::endl;

    std::cout << "\nGenerating subnodes for " << nodeMap.size() << " nodes..." << std::endl;
    unsigned int threadCount = std::thread::hardware_concurrency();
    std::cout << "\n" << threadCount << " threads found, splitting workload accordingly..." << std::endl;
    time(&startTime);
    GenerateSubNodes(0,10370);
    /*std::vector<std::thread> threads;
    unsigned int threadInterval = 10000 / threadCount;
    for (unsigned int i = 0; i < threadCount; i++)
    {
        unsigned int lowerLimit = i * threadInterval;
        unsigned int upperLimit = ((i + 1) * threadInterval - 1);
        threads.at(i) = std::thread(&GenerateSubNodes, lowerLimit, upperLimit);
    }
    for (auto &t : threads) {
        t.join();
    }*/
    time(&endTime);
    std::cout << "Generated " << nodeMap.size() * nodeMap.size() << " subnodes in " << difftime(endTime, startTime) << " seconds." << std::endl;
    std::vector<std::string> trainingData;
    fManager.LoadTrainingData(trainingData, "./assets/TrainingData.txt");
    std::cout << "Loaded training data " << std::endl;
    dAnalyser.AddData(trainingData, nodeMap, wordList);
    GenerateSentence();

}


