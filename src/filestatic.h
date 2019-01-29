#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <iostream>
#include <fstream>
#include "output.h"
#include "model.h"
#include <memory>
#include "output.h"
#include <thread>

class Filestatic: public Output
{
public:
    Filestatic(Model*model);
    void createFile(std::string name);
    void closeFile();
    void print();
private:
    std::ofstream _outfile;
};

#endif // FILEOUTPUT_H
