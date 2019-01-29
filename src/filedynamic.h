#ifndef FILEDIYNAMIC_H
#define FILEDIYNAMIC_H

#include <thread>
#include "output.h"
#include <fstream>

class Filedynamic: public Output
{
public:
    Filedynamic(Model*model);
    void createFile(std::string name);
    void closeFile();
    void print();
private:
    std::ofstream _outfile;
};

#endif // FILEDIYNAMIC_H
