#ifndef FILEMANAGER_HPP     //If the header hasn't already been defined
#define FILEMANAGER_HPP     //Define the header and everything in it

//Add the following libraries to this header
#include <vector>                    //Vector for creating vectors of nodes.  I use vector as it's generally more efficient than list
#include <fstream>                   //Fstream for file operations
#include <string>                    //String for the usage of strings, as opposed to arrays or vectors of characters
#include <iostream>

#include "Word.hpp"
#include "Node.hpp"                  //Include node so that the node map can be written from and read to

class FileManager                    //Create a class called FileManager
{
public:                          //Publicly declared functions and variables:
    FileManager();               //Constructor
    virtual ~FileManager();      //Destructor


    void LoadDictionary(std::vector<Word> & wordList, std::string filepath);
    void LoadTrainingData(std::vector<std::string> & trainingData, std::string filepath);

protected:

private:
};

#endif // FILEMANAGER_HPP
