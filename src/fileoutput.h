#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <iostream>
#include <fstream>
#include "output.h"
#include "model.h"
#include <memory>
#include "output.h"

class StateFout;

class Fileoutput: public Output
{
public:
    Fileoutput(Model*model);
    void createFile(std::string name);
    void closeFile();
    void update(const std::string &str);
    void update();
    void print();
private:
    std::ofstream _outfile;
};

#endif // FILEOUTPUT_H
