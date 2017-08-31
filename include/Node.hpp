#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

class Node
{
public:
    Node(short i);
    virtual ~Node();

    void AddWeight();
    short GetIndex();
    short GetWeight();


protected:

private:
    short index = 0;
    short weight = 0;

};

#endif // NODE_HPP
