#include "Node.hpp"

Node::Node(short _index)
{
    index = _index;
}

Node::~Node()
{
    //dtor
}

void Node::AddWeight()
{
    weight += 1;
}

short Node::GetIndex()
{
    return index;
}

short Node::GetWeight()
{
    return weight;
}
