#ifndef BLOCKOUTPUT_H
#define BLOCKOUTPUT_H

#include <string>
#include <vector>
#include <memory>
#include "model.h"
#include "output.h"

class StateCout;

class Blockoutput:public Output{
public:
    Blockoutput(Model *model);
    void update();
    void print();
};

#endif // BLOCKOUTPUT_H
