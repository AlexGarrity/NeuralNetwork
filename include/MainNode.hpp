#ifndef MAINNODE_HPP
#define MAINNODE_HPP

#include "Node.hpp"
#include "Word.hpp"

#include <vector>
#include <random>

class MainNode
{
public:
    MainNode(short i);

    void IncreaseWeight(short index);
    void GenerateSubNodes(std::vector<Word> & wordList);
    short NextWord();

protected:

private:
    short identifier = 0;
    float connections = 0;
    std::vector<Node> weightMap;

};

#endif // MAINNODE_HPP
