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
    if (endPoint > nodeMap.size() - 1)
    {
        endPoint = nodeMap.size() - 1;
        startPoint = 0;
    }
    Mutex.lock();
    for (unsigned int i = startPoint; i < endPoint; i++)
    {
        nodeMap[i].GenerateSubNodes(wordList);
    }
    Mutex.unlock();
}

void NeuralNetwork::SentenceInput(std::vector<std::string> &sentence) {

}

std::vector<std::string> NeuralNetwork::GenerateSentence()
{
    short length = 0;
    short currentWord = rand() % 10000;
    std::vector<std::string> sentence;
    std::cout << "\nGenerating a sentence..." << std::endl;
    sentence.push_back(wordList[currentWord].word);
    unsigned char sentenceLength = rand() % 9;
    std::cout << sentence.size() << " is the sentence size" << std::endl;
    while (sentence.size() < sentenceLength)
    {
        currentWord = nodeMap[currentWord].NextWord();
        if (currentWord != -1)
        {
            sentence.push_back(wordList[currentWord].word);
            length ++;
        }
        else
        {
            std::cout << "No extra connections found, final result: " << std::endl;
            break;
        }
    }
    return sentence;
}

void NeuralNetwork::GenerateSentences() {
    bool exit = false;
    while (exit == false) {
        std::vector<std::string> sentence = GenerateSentence();
        SentenceInput(sentence);
    }
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

    /** I don't think this actually decreases the time taken to create all the sub nodes **/
    std::cout << "\n" << threadCount << " threads found, splitting workload accordingly..." << std::endl;
    time(&startTime);
    std::vector<std::thread> threads;
    unsigned int threadInterval = 10000 / threadCount;
    for (unsigned int i = 0; i < threadCount; i++)
    {
        unsigned int lowerLimit = i * threadInterval;
        unsigned int upperLimit = ((i + 1) * threadInterval - 1);
        threads.push_back(std::thread(GenerateSubNodes, this, lowerLimit, upperLimit));
    }
    for (unsigned int i = 0; i < threadCount; i++) {
        threads.at(i).join();
    }
    time(&endTime);
    std::cout << "Generated " << nodeMap.size() * nodeMap.size() << " subnodes in " << difftime(endTime, startTime) << " seconds." << std::endl;

    std::vector<std::string> trainingData;
    fManager.LoadTrainingData(trainingData, "./assets/TrainingData.txt");
    std::cout << "Loaded training data " << std::endl;
    dAnalyser.AddData(trainingData, nodeMap, wordList);

    GenerateSentences();

}


