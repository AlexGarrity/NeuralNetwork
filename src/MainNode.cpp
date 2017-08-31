#include "MainNode.hpp"

MainNode::MainNode(short _index)
{
    identifier = _index;
}

void MainNode::IncreaseWeight(short index)
{
    weightMap[index].AddWeight();
    connections ++;
}

short MainNode::NextWord()
{
    float minimumConnection = 100;
    std::vector <float> weights;
    while (minimumConnection > 10 && weights.size() < 5)
    {
        for (unsigned int i = 0; i < weightMap.size(); i++)
        {
            if (weightMap[i].GetWeight() != 0)
            {
                float connectionWeight = weightMap[i].GetWeight();
                connectionWeight /= connections;
                connectionWeight *= 100;
                if (connectionWeight > minimumConnection)
                {
                    weights.push_back(weightMap[i].GetIndex());
                }
            }
        }
        minimumConnection -= 5;
    }
    return weights[rand()%5];
}

void MainNode::GenerateSubNodes(std::vector<Word> & wList)
{
    std::vector<Word> wordList = wList;
    for (unsigned int i = 0; i < wordList.size() -1; i++)
    {
        weightMap.push_back(Node(i));
    }
}
