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
    float lowestConnection = 0;
    bool lowestSet = false;
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
                    if (lowestSet == false)
                    {
                        lowestConnection = connectionWeight - 10;
                    }
                    if (connectionWeight >= lowestConnection)
                    {
                        if (weights.size() <= 5)
                        {
                            weights.push_back(weightMap[i].GetIndex());
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        minimumConnection -= 1;
    }
    if (weights.size() != 0)
    {
        return weights[rand()%weights.size()];
    }
    else
    {
        return rand() % 10000;
    }
}

void MainNode::GenerateSubNodes(std::vector<Word> & wList)
{
    std::vector<Word> wordList = wList;
    for (unsigned int i = 0; i < wordList.size() -1; i++)
    {
        weightMap.push_back(Node(i));
        for (int j = 0; j < rand() % 10; j++)
        {
            IncreaseWeight(i);
        }
    }
}
